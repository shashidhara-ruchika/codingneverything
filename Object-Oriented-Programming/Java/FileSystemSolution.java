import java.util.*;
import java.util.stream.Collectors;

public class FileSystemSolution {
    String[] solution(String[][] queries) {

        List<String> result = new ArrayList<>();
        FileSystem fs = new FileSystem();

        for (String[] query : queries) {
            switch (query[0]) {
                case "ADD_FILE": {
                    Boolean addFileResult = fs.addFile(query[1], Long.parseLong(query[2]), "admin");
                    result.add(addFileResult.toString());
                    break;
                }

                case "GET_FILE_SIZE": {
                    File file = fs.files.get(query[1]);
                    if (file == null) {
                        result.add("");
                    } else {
                        result.add(file.size.toString());
                    }
                    break;
                }

                case "DELETE_FILE": {
                    Boolean deleteFileResult = fs.deleteFile(query[1]);
                    result.add(deleteFileResult.toString());
                    break;
                }

                case "COPY_FILE": {
                    Boolean copyFileResult = fs.copyFile(query[1], query[2]);
                    result.add(copyFileResult.toString());
                    break;
                }

                case "ADD_USER": {
                    Boolean addUserResult = fs.addUser(query[1], Long.parseLong(query[2]));
                    result.add(addUserResult.toString());
                    break;
                }

                case "ADD_FILE_BY": {
                    Boolean addFileResult = fs.addFile(query[1], Long.parseLong(query[2]), query[3]);
                    if (addFileResult) {
                        result.add(fs.users.get(query[3]).remainingCapacity.toString());
                    } else {
                        result.add("");
                    }
                    break;
                }

                case "FIND_FILE": {
                    List<String> files = fs.sortFiles(null, query[1], query[2], null, null);
                    if (files.isEmpty()) {
                        result.add("");
                    } else {
                        files = files.stream().map(file -> {
                            File f = fs.files.get(file);
                            return f.name + "(" + f.size + ")";
                        }).collect(Collectors.toList());
                        result.add(String.join(", ", files));
                    }
                    break;
                }

                case "GET_N_LARGEST": {
                    List<String> files = fs.sortFiles(null, "", query[1], null, Long.parseLong(query[2]));
                    if (files.isEmpty()) {
                        result.add("");
                    } else {
                        files = files.stream().map(file -> {
                            File f = fs.files.get(file);
                            return f.name + "(" + f.size + ")";
                        }).collect(Collectors.toList());
                        result.add(String.join(", ", files));
                    }
                    break;
                }

                case "MERGE_USER": {
                    Boolean mergeUserResult = fs.mergeUser(query[1], query[2]);
                    if (mergeUserResult) {
                        result.add(fs.users.get(query[1]).remainingCapacity.toString());
                    } else {
                        result.add("");
                    }
                    break;
                }

                case "UPDATE_CAPACITY": {
                    List<String> removedFiles = fs.updateUserCapacity(query[1], Long.parseLong(query[2]));
                    if (removedFiles == null) {
                        result.add("");
                    } else {
                        result.add(Integer.valueOf(removedFiles.size()).toString());
                    }
                    break;
                }
            }
        }

        return result.stream().toArray(String[]::new);
    }

    public class FileSystem {
        Map<String, File> files;
        Map<String, User> users;
        User admin;

        FileSystem() {
            files = new HashMap<>();
            users = new HashMap<>();
            admin = new User("admin", Long.MAX_VALUE);
            users.put(admin.name, admin);
        }

        public Boolean addUser(String user, Long capacity) {
            if (users.containsKey(user)) {
                return false;
            }
            users.put(user, new User(user, capacity));
            return true;
        }

        public User getUser(String user) {
            return users.get(user);
        }

        public File getFile(String file) {
            return files.get(file);
        }

        public Boolean isAdmin(User user) {
            return user.equals(admin);
        }

        public Boolean addFile(String file, Long capacity, String user) {

            File exisitingFile = files.get(file);
            if (exisitingFile != null) {
                return false;
            }

            User owner = getUser(user);

            if (owner == null || owner.remainingCapacity < capacity) {
                return false;
            }

            if (!isAdmin(owner)) {
                owner.remainingCapacity -= capacity;
            }

            File newFile = new File(file, capacity, owner);
            files.put(file, newFile);
            return true;

        }

        public Boolean deleteFile(String file) {

            File fileToDelete = files.get(file);
            if (fileToDelete == null) {
                return false;
            }

            User owner = fileToDelete.owner;

            if (!isAdmin(owner)) {
                owner.remainingCapacity += fileToDelete.size;
            }

            files.remove(file);
            return true;
        }

        public Boolean copyFile(String source, String destination) {

            File sourceFile = files.get(source);
            File destinationFile = files.get(destination);

            if (sourceFile == null || destinationFile != null) {
                return false;
            }

            return addFile(destination, sourceFile.size, sourceFile.owner.name);
        }

        public List<String> sortFiles(List<String> inputFiles, String prefix, String suffix, String user, Long n) {
            if (n == null) {
                n = Long.valueOf(files.size());
            }
            if (inputFiles == null) {
                inputFiles = files.keySet().stream().collect(Collectors.toList());
            }
            return inputFiles
                    .stream()
                    .filter(file -> user == null ? true : (user.equals(files.get(file).owner.name)))
                    .filter(file -> (file.startsWith(prefix) && file.endsWith(suffix)))
                    .sorted(((file1, file2) -> 
                        {
                            File f1 = files.get(file1);
                            File f2 = files.get(file2);
                            if (f1.size.equals(f2.size)) {
                                return file1.compareTo(file2);
                            } else {
                                return f2.size.compareTo(f1.size);
                            }
                        }
                    ))
                    .limit(n)
                    .collect(Collectors.toList());
        }

        public Boolean mergeUser(String user1, String user2) {
            User u1 = users.get(user1);
            User u2 = users.get(user2);

            if (u1 == null || u2 == null) {
                return false;
            }

            if (u1.equals(u2)) {
                return false;
            }

            if (isAdmin(u2)) {
                User temp = u1;
                u1 = u2;
                u2 = temp;
            }

            if(!isAdmin(u1)) {
                u1.maxCapacity += u2.maxCapacity;
                u1.remainingCapacity += u2.remainingCapacity;
            } 
                
            users.remove(u2.name);

            User uadd = u1;
            User urm = u2;

            files.keySet().stream().forEach(file -> {
                File f = files.get(file);
                if (f.owner.equals(urm)) {
                    f.owner = uadd;
                }
            });
            return true;
        
        }

        public List<String> updateUserCapacity(String user, Long capacity) {
            
            List<String> removedFiles = new ArrayList<>();
            
            User fileUser = getUser(user);

            if (fileUser == null) {
                return null;
            }

            if (isAdmin(fileUser)) {
                return removedFiles;
            } else if (capacity > fileUser.maxCapacity) {
                Long currentUsedCapacity = fileUser.maxCapacity - fileUser.remainingCapacity;
                fileUser.maxCapacity = capacity;
                fileUser.remainingCapacity = capacity - currentUsedCapacity;
            } else {
                List<String> sortedFiles = sortFiles(null, "", "", user, null);

                Long currentUsedCapacity = fileUser.maxCapacity - fileUser.remainingCapacity;

                while (currentUsedCapacity > capacity && !sortedFiles.isEmpty()) {
                    String file = sortedFiles.get(0);
                    Long fileSize = files.get(file).size;
                    deleteFile(file);
                    removedFiles.add(file);
                    sortedFiles.remove(0);
                    currentUsedCapacity -= fileSize;
                }

                fileUser.maxCapacity = capacity;
                fileUser.remainingCapacity = capacity - currentUsedCapacity;
            }
            return removedFiles;
        }
    }

    public class User {
        String name;
        Long maxCapacity;
        Long remainingCapacity;

        User(String name, Long capacity) {
            this.name = name;
            this.maxCapacity = capacity;
            this.remainingCapacity = capacity;
        }

        @Override
        public String toString() {
            return "User: " + name + " " + maxCapacity + " " + remainingCapacity;
        }
    }

    public class File {
        String name;
        Long size;
        User owner;

        File(String name, Long size, User owner) {
            this.name = name;
            this.size = size;
            this.owner = owner;
        }

        @Override
        public String toString() {
            return "File: " + name + " " + size + " " + owner.name;
        }
    }

    public static void main(String[] args) {
        
        String[][] queries = new String[][]{
                {"ADD_USER", "user1", "100"},
                {"ADD_USER", "user2", "200"},
                {"ADD_FILE_BY", "file1", "50", "user1"},
                {"ADD_FILE_BY", "file2", "100", "user2"},
                {"COPY_FILE", "file1", "file3"},
                {"GET_FILE_SIZE", "file3"},
                {"FIND_FILE", "fi", "", "", ""},
                {"GET_N_LARGEST", "", "2"},
                {"MERGE_USER", "user1", "user2"},
                {"UPDATE_CAPACITY", "user1", "600"},
                {"FIND_FILE", "fi", "", "user1", ""},
                {"UPDATE_CAPACITY", "user1", "100"},
                {"FIND_FILE", "fi", "", "user1", ""},
                {"UPDATE_CAPACITY", "user1", "70"},
                {"FIND_FILE", "fi", "", "user1", ""},
        };
        /* 
        user1 0 file1 50 file3 50
        user2 100 file2 100
        
        user1 100 file1 50 file3 50 file2 100
        */

        FileSystemSolution fs = new FileSystemSolution();

        String[] results = fs.solution(queries);
        System.out.println("--- FileSystemSolution ---");
        for (String result : results) {
            System.out.println(result);
        }
        
    }

}
