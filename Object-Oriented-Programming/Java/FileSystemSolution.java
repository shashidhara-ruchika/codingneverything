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
                }

                case "GET_FILE_SIZE": {
                    Long fileSize = fs.files.get(query[1]);
                    if (fileSize == null) {
                        result.add("");
                    } else {
                        result.add(fileSize.toString());
                    }
                }

                case "DELETE_FILE": {
                    Boolean deleteFileResult = fs.deleteFile(query[1]);
                    result.add(deleteFileResult.toString());
                }

                case "COPY_FILE": {
                    Boolean copyFileResult = fs.copyFile(query[1], query[2]);
                    result.add(copyFileResult.toString());
                }

                case "ADD_USER": {
                    Boolean addUserResult = fs.addUser(query[1], Long.parseLong(query[2]));
                    result.add(addUserResult.toString());
                }

                case "ADD_FILE_BY": {
                    Boolean addFileResult = fs.addFile(query[1], Long.parseLong(query[2]), query[3]);
                    if (addFileResult) {
                        result.add(fs.users.get(query[3]).toString());
                    } else {
                        result.add("");
                    }
                }

                case "FIND_FILE": {
                    List<String> files = fs.getNLargestFiles(query[1], query[2], fs.files.size(), "");
                    if (files.isEmpty()) {
                        result.add("");
                    } else {
                        files = files.stream().map(file -> file + "(" + fs.files.get(file) + ")").collect(Collectors.toList());
                        result.add(String.join(", ", files));
                    }
                }

                case "GET_N_LARGEST": {
                    List<String> files = fs.getNLargestFiles("", query[1], Integer.parseInt(query[2]), "");
                    if (files.isEmpty()) {
                        result.add("");
                    } else {
                        files = files.stream().map(file -> file + "(" + fs.files.get(file) + ")").collect(Collectors.toList());
                        result.add(String.join(", ", files));
                    }

                }

                case "MERGE_USER": {
                    Boolean mergeUserResult = fs.mergeUser(query[1], query[2]);
                    if (mergeUserResult) {
                        result.add(fs.users.get(query[1]).toString());
                    } else {
                        result.add("");
                    }
                }

                case "UPDATE_CAPACITY": {
                    List<String> removedFiles = fs.updateUserCapacity(query[1], Long.parseLong(query[2]));
                    if (removedFiles == null) {
                        result.add("");
                    } else {
                        result.add(Integer.valueOf(removedFiles.size()).toString());
                    }
                }
            }
        }

        return result.stream().toArray(String[]::new);
    }

    public class FileSystem {
        Map<String, Long> files; // files, capacity
        Map<String, Long> users; // user, remaining capacity
        Map<String, String> fileOwners; // file, user

        FileSystem() {
            files = new HashMap<>();
            users = new HashMap<>();
            fileOwners = new HashMap<>();
            users.put("admin", Long.MAX_VALUE);
        }

        public Boolean addUser(String user, Long capacity) {
            if (users.containsKey(user)) {
                return false;
            }
            users.put(user, capacity);
            return true;
        }

        public Boolean addFile(String file, Long capacity, String user) {
            if (files.containsKey(file) || !users.containsKey(user) || users.get(user) < capacity) {
                return false;
            }
            files.put(file, capacity);
            if (!user.equals("admin")) {
                users.put(user, users.get(user) - capacity);
            }
            fileOwners.put(file, user);
            return true;
        }

        public Boolean deleteFile(String file) {
            if (!files.containsKey(file)) {
                return false;
            }
            String user = fileOwners.get(file);
            Long fileCapacity = files.get(file);
            files.remove(file);
            if (!user.equals("admin")) {
                users.put(user, users.get(user) + fileCapacity);
            }
            fileOwners.remove(file);
            return true;
        }

        public Boolean copyFile(String source, String destination) {
            if (!files.containsKey(source) || files.containsKey(destination)) {
                return false;
            }
            return addFile(destination, files.get(source), fileOwners.get(source));
        }

        public List<String> getNLargestFiles(String prefix, String suffix, int n, String user) {
            List<String> result = new ArrayList<>();

            List<String> queryfiles = new ArrayList<>();

            for (String file : files.keySet()) {
                if (file.startsWith(prefix) && file.endsWith(suffix)) {
                    if (user.equals("")) {
                        queryfiles.add(file);
                    } else if (users.get(user) != null && fileOwners.get(file).equals(user)) {
                        queryfiles.add(file);
                    }
                }
            }

            if (!queryfiles.isEmpty()) {
                Collections.sort(queryfiles, new Comparator<String>() {
                    public int compare(String s1, String s2) {
                        Long v1 = files.get(s1);
                        Long v2 = files.get(s2);

                        if (v1.equals(v2)) {
                            return s1.compareTo(s2);
                        }

                        return v2.compareTo(v1);
                    }
                });

                for (int i = 0; i < n && i < queryfiles.size(); i++) {
                    result.add(queryfiles.get(i));
                }
            }

            return result;
        }

        public Boolean mergeUser(String user1, String user2) {
            if (!users.containsKey(user1) || !users.containsKey(user2)) {
                return false;
            }

            if (user1.equals("admin") || user2.equals("admin")) {
                users.put(user1, Long.MAX_VALUE);
            } else {
                users.put(user1, users.get(user1) + users.get(user2));
            }
            users.remove(user2);

            for (String file : files.keySet()) {
                if (fileOwners.get(file).equals(user2)) {
                    fileOwners.put(file, user1);
                }
            }

            return true;
        }

        public List<String> updateUserCapacity(String user, Long capacity) {
            if (!users.containsKey(user)) {
                return null;
            }

            List<String> removedFiles = new ArrayList<>();

            if (user.equals("admin")) {
                return removedFiles;
            } else if (capacity > users.get(user)) {
                users.put(user, capacity);
            } else {                
                List<String> sortedFiles = getNLargestFiles("", "", files.size(), user);

                while (users.get(user) >= capacity && !sortedFiles.isEmpty()) {
                    String file = sortedFiles.get(0);
                    deleteFile(file);
                    removedFiles.add(file);
                    sortedFiles.remove(0);
                }

                return removedFiles;
            }

            return removedFiles;
        }
    }

}
