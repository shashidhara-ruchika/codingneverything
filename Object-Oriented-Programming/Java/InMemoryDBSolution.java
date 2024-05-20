import java.util.*;
import java.util.stream.Collectors;

public class InMemoryDBSolution {

    String[] solution(String[][] queries) {

        List<String> sol = new ArrayList<>();

        DB database = new DB();

        for (String[] query : queries) {
            switch (query[0]) {
                case "SET": {
                    String result = database.set(query[1], query[2], query[3]);
                    sol.add(result);
                    break;
                }
                case "GET": {
                    String result = database.get(query[1], query[2], null);
                    sol.add(result);
                    break;
                }
                case "DELETE": {
                    Boolean result = database.delete(query[1], query[2], null);
                    sol.add(result.toString());
                    break;
                }
                case "SCAN": {
                    List<String> result = database.scan(query[1], "", "", null);
                    sol.add(String.join(",", result));
                    break;
                }
                case "SCAN_BY_PREFIX": {
                    List<String> result = database.scan(query[1], query[2], "", null);
                    sol.add(String.join(",", result));
                    break;
                }
                case "SET_AT": {
                    String result = database.set(query[1], query[2], query[3]);
                    sol.add(result);
                    break;
                }
                case "SET_AT_WITH_TTL": {
                    String result = database.setAtWithTtl(query[1], query[2], query[3], Long.parseLong(query[4]),
                            Long.parseLong(query[5]));
                    sol.add(result);
                    break;
                }
                case "GET_AT": {
                    String result = database.get(query[1], query[2], Long.parseLong(query[3]));
                    sol.add(result);
                    break;
                }
                case "DELETE_AT": {
                    Boolean result = database.delete(query[1], query[2], Long.parseLong(query[3]));
                    sol.add(result.toString());
                    break;
                }
                case "SCAN_AT": {
                    List<String> result = database.scan(query[1], "", "", Long.parseLong(query[2]));
                    sol.add(String.join(",", result));
                    break;
                }
                case "SCAN_BY_PREFIX_AT": {
                    List<String> result = database.scan(query[1], query[2], "", Long.parseLong(query[3]));
                    sol.add(String.join(",", result));
                    break;
                }
            }

        }

        return sol.stream().toArray(String[]::new);

    }

}

class DB {
    Map<String, Record> rows;

    DB() {
        this.rows = new HashMap<>();
    }

    public Record getRecord(String key) {
        return rows.get(key);
    }

    public Record createRecord(String key) {
        Record record = new Record(key);
        rows.put(key, record);
        return record;
    }

    String set(String key, String field, String value) {
        Record record = getRecord(key);
        if (record == null) {
            record = createRecord(key);
        }
        record.setField(field, value);
        return "";
    }

    String setAtWithTtl(String key, String field, String value, Long timestamp, Long ttl) {
        Record record = getRecord(key);
        if (record == null) {
            record = createRecord(key);
        }
        record.setField(field, value, timestamp + ttl);
        return "";
    }

    String get(String key, String field, Long currentTimestamp) {
        Record record = getRecord(key);
        if (record == null) {
            return "";
        }
        Field f = record.getField(field, currentTimestamp);
        if (f == null) {
            return "";
        }

        return f.value;
    }

    Boolean delete(String key, String field, Long currentTimestamp) {
        Record record = getRecord(key);
        if (record == null) {
            return false;
        }
        record.deleteField(field, currentTimestamp);
        return true;
    }

    List<String> scan(String key, String prefix, String suffix, Long currentTimestamp) {
        Record record = getRecord(key);
        if (record == null) {
            return new ArrayList<>();
        }
        return record.fields.values()
                .stream()
                .filter(
                        f -> f.name.startsWith(prefix) && f.name.endsWith(suffix)
                                && currentTimestamp != null && !record.hasFieldExpired(f, currentTimestamp))
                .sorted()
                .map(f -> f.printFieldValue())
                .collect(Collectors.toList());
    }

}

class Record {
    String key;
    Map<String, Field> fields;

    Record(String key) {
        this.key = key;
        this.fields = new HashMap<>();
    }

    public Field getField(String field) {
        return fields.get(field);
    }

    public Field getField(String field, Long timestamp) {
        Field f = fields.get(field);
        if (f == null) {
            return null;
        }

        if (timestamp != null && hasFieldExpired(f, timestamp)) {
            return null;
        }

        return f;
    }

    public void setField(String field, String value) {
        fields.put(field, new Field(field, value));
    }

    public void setField(String field, String value, Long expiry) {
        fields.put(field, new Field(field, value, expiry));
    }

    public Boolean deleteField(String field, Long timestamp) {
        Field f = fields.get(field);
        if (f == null) {
            return false;
        }

        if (timestamp != null && hasFieldExpired(f, timestamp)) {
            return false;
        }

        fields.remove(field);
        return true;
    }

    public Boolean hasFieldExpired(Field field, Long currentTimestamp) {
        return field.expiryTimestamp != null && currentTimestamp > field.expiryTimestamp;
    }
}

class Field implements Comparable<Field> {
    String name;
    String value;
    Long expiryTimestamp;

    Field(String name, String value) {
        this.name = name;
        this.value = value;
        this.expiryTimestamp = null;
    }

    Field(String name, String value, Long expiryTimestamp) {
        this.name = name;
        this.value = value;
        this.expiryTimestamp = expiryTimestamp;
    }

    @Override
    public int compareTo(Field otherField) {
        return this.name.compareTo(otherField.name);
    }

    public String printFieldValue() {
        return new StringBuilder()
                .append(name)
                .append("(")
                .append(value)
                .append(")")
                .toString();
    }

}
