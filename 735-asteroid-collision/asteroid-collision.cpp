class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>st;
        //two asteriods will only meet if  top is +ve and other is -ve -><- and <- -> will also never meet
        st.push(as[0]);
        for(int i=1;i<as.size();i++){
          if(st.size()==0)st.push(as[i]);
          else if(st.top() * as[i] >0)st.push(as[i]);
          else if(st.top()<0 && as[i]>0)st.push(as[i]);
          else {
              int m=as[i];
              while(st.size() && (st.top()>0 && m<0)){
                  if(abs(m)==abs(st.top())){
                      st.pop();
                      m=0;
                      break;
                  }

                  else if(abs(m)>abs(st.top())){
                      st.pop();
                  }
                  else{
                      m=st.top();
                      st.pop();
                  }
              }
              if(m!=0)st.push(m);
          }
        }  
        vector<int>ans(st.size()); 
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }    
        return ans;
    }
};