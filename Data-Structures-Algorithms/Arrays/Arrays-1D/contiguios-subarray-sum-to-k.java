// https://leetcode.com/discuss/interview-question/1581706/codesignal-practice-test

int solution(int[] a, int m, int k) {
    Map<Integer,Integer> map = new HashMap();
    int ans=0;
    Set<Long> set = new HashSet<>();
    for(int i=0;i<m &&i<a.length;i++){
        if(map.containsKey(k-a[i])){
            long cur = a[i]*(k-a[i]);
            if(!set.contains(cur)) set.add(cur);
        }
        if (map.containsKey(a[i])) map.put(a[i],map.get(a[i])+1);
        else map.put(a[i],1);
    }
    if(set.size()>0) ans++;
    int le=0;
    for(int i=m;i<a.length;i++){
        if(map.get(a[le])>1){
            map.put(a[le],map.get(a[le])-1);
            if(a[le]==k-a[le] && map.get(a[le])==1){
                long cur = a[le]*(k-a[le]);
                set.remove(cur);
            }
        } 
        else {
            if(map.containsKey(k-a[le])){
                long cur = a[le]*(k-a[le]);
                set.remove(cur);
            }
            map.remove(a[le]);
        }
        le++;
        if(map.containsKey(k-a[i])){
            long cur = a[i]*(k-a[i]);
            if(!set.contains(cur)) set.add(cur);
        }
        if(set.size()>0) ans++;
        if (map.containsKey(a[i])) map.put(a[i],map.get(a[i])+1);
        else map.put(a[i],1);
    }
    return ans;
}