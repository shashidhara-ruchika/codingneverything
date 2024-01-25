// https://leetcode.com/discuss/interview-question/922241/quora-oa-2020-ways-to-split-string

int solution(String s) {
      int n=s.length();
      int ans=0;
      for(int i=1;i<n-1;i++){
          for(int j=i+1;j<n;j++){
              String s1=s.substring(0,i);
              String s2=s.substring(i,j);
              String s3=s.substring(j,n);
              if(!(s1+s2).equals(s2+s3) && !(s2+s3).equals(s3+s1) && !(s1+s2).equals(s3+s1))
                  ans++;
          }
      }
      return ans;
}