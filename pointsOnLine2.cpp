// https://www.interviewbit.com/problems/points-on-the-straight-line/
int Solution::maxPoints(vector<int> &A, vector<int> &B) {

    if(A.size()<=2)
        return A.size();
    
    int result=0;

    for(int i=0;i<A.size();i++){
        int dup = 1;
        int vert =0;

        map <double, int> M;
        
        for(int j=0;j<A.size();j++){

            if(i!=j){
                double x = A[j] - A[i];
                double y = B[j] - B[i];
                
                if((int)x==0){
                    
                    if((int)y==0){
                        dup++;
                    }
                    
                    else{
                        vert++;
                    }
                }
                
                else{
                    M[y/x]+=1;
                }
            }
        }
        int pp =0;
        
        for(map <double, int>::iterator it=M.begin() ;it!=M.end(); it++){
            result=max(result,it->second+dup);
        }
        
        result = max(result, dup+vert);

    }
    return result;
}
