import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class InMemoryDBSolution2 {

    String[] solution(String[][] queries) {
    List<String> sol = new ArrayList<>();
    
    DB database = new DB();
    
    for(String[] query: queries){
        switch (query[0]) {
            case "SET": {
                String result = database.set(query[1], query[2], query[3]);
                sol.add(result);
                break;
            }
            case "GET": {
                String result = database.get(query[1], query[2]);
                sol.add(result);
                break;
            }
            case "DELETE": {
                Boolean result = database.delete(query[1], query[2]);
                sol.add(result.toString());
                break;
            }
            case "SCAN": {
                String result = database.scan(query[1]);
                sol.add(result);
                break;
            }
            case "SCAN_BY_PREFIX": {
                String result = database.scanByPrefix(query[1], query[2]);
                sol.add(result);
                break;
            }
            case "SET_AT": {
                String result = database.setAt(query[1], query[2], query[3], Long.parseLong(query[4]));
                sol.add(result);
                break;
            }
            case "SET_AT_WITH_TTL": {
                String result = database.setAtWithTtl(query[1], query[2], query[3], 
                Long.parseLong(query[4]), 
                Long.parseLong(query[5]));
                sol.add(result);
                break;
            }
            case "GET_AT": {
                String result = database.getAt(query[1], query[2], Long.parseLong(query[3]));
                sol.add(result);
                break;
            }
        }
    }
    
    
    return sol.stream().toArray(String[]::new);
}

class Field{
    String name;
    String value;
    Long ttl;
    
    Field(String name, String valueString){
        this.name = name;
        this.value = valueString;
        ttl = null; //So that it is backward compatible
    }
    
    Field(String name, String value, Long ttl){
        this.name = name;
        this.value = value;
        this.ttl = ttl;
    }
}

class Record{
    String key;
    Map<String, Field> columns;
    
    Record(String key) {
        this.key = key;
        this.columns = new HashMap<>();
    }
    
    public void setFieldAndValue(String field, String value){
        columns.put(field, new Field(field, value));
    }
    
    public void setFieldAndValueTTL(String field, String value, Long ttl){
        columns.put(field, new Field(field, value, ttl));
    }
    
    public String getValue(String field){
        if(columns.get(field) == null){
            return "";
        }
        else {
            return columns.get(field).value;
        }
    }
    
    public Long getTTL(String field){
        if(columns.get(field) == null){
            return null;
        }
        else {
            return columns.get(field).ttl;
        }
    }
    
    public Boolean deleteFieldAndValue(String field){
        if(columns.get(field) == null){
            return false;
        }
        else {
            columns.remove(field);
            return true;
        }
    }
    
    public List<String> sortLex(Map<String, Field> subset){
        List<String> result = subset.keySet().stream().collect(Collectors.toList());
        Collections.sort(result);
        return result;
    }
    
    public String displaySortLex(List<String> sortedFields){
        if(sortedFields.isEmpty()){
            return "";
        }
        else{
            List<String> result2 = sortedFields.stream()
            .map(field -> field + "(" + this.getValue(field) + ")")
            .collect(Collectors.toList());
            
            return String.join(", ", result2);
        }
    }
    
    public Map<String, Field> filter(String prefix){
        Map<String, Field> result = new HashMap<>(); 
        for(String field: this.columns.keySet()){
            if(field.startsWith(prefix)){
                result.put(field, columns.get(field));
            }
        }
        return result;
    }
    
}


class DB{
    Map<String, Record> rows;
    
    DB(){
        this.rows = new HashMap<>();
    }
    
    public String set(String key, String field, String value){
        Record r;
        if(rows.get(key) == null){
            r = createRecord(key);
        }
        else {
            r = getRecord(key);
        }
        r.setFieldAndValue(field, value);
        return "";
    }
    
    public String setAt(String key, String field, String value, Long timestamp){
        return set(key, field, value);
    }
    
    public String setAtWithTtl(String key, String field, String value, Long timestamp, Long ttl){
        Record r;
        if(rows.get(key) == null){
            r = createRecord(key);
        }
        else {
            r = getRecord(key);
        }
        r.setFieldAndValueTTL(field, value, timestamp + ttl);
        return "";
    }
    
    public String get(String key, String field){
        if(rows.get(key) == null){
            return "";
        }
        else {
            Record r = getRecord(key);
            return r.getValue(field);
        }
    }
    
    public String getAt(String key, String field, Long timestamp){
        if(rows.get(key) == null){
            return "";
        }
        else {
            Record r = getRecord(key);
            return r.getValue(field);
        }
    }
    
    public Boolean delete(String key, String field){
        if(rows.get(key) == null){
            return false;
        }
        else {
            Record r = getRecord(key);
            return r.deleteFieldAndValue(field);
        }
    }
    
    public String scan(String key){
        if(rows.get(key) == null){
            return "";
        }
        else {
            Record r = getRecord(key);
            List<String> sortedFields = r.sortLex(r.columns);
            return r.displaySortLex(sortedFields);
        }
    }
    
    public String scanByPrefix(String key, String prefix) {
        if(rows.get(key) == null){
            return "";
        }
        else{
            Record r = getRecord(key);
            Map<String, Field> filteredColumns = r.filter(prefix);
            List<String> sortedFields = r.sortLex(filteredColumns);
            return r.displaySortLex(sortedFields);
        }
    }
    
    public Record createRecord(String key){
        Record r = new Record(key);
        rows.put(key, r);
        return r;
    }
    
    public Record getRecord(String key){
        if(rows.get(key) == null){
            return null;
        }
        else {
            return rows.get(key);
        }
    }
    
    
}
    
}

