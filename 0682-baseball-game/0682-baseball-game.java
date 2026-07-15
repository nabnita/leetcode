class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> st = new Stack<>();
        for(String c : operations){
        if(c.equals("C")){
            st.pop();
        }
        else if(c.equals("D")){
            st.push(st.peek()*2);
        }
        else if(c.equals("+")){
            int val1 = st.peek();
            st.pop();
            int val2 = st.peek();
            st.push(val1);
            st.push(val1+val2);
        }
        else{
            st.push(Integer.parseInt(c));
        }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.peek();
            st.pop();
        }
        return ans;
    }
}