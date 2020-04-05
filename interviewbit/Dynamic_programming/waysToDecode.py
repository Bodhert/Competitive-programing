ass Solution:
    
    def isValid(self, substr):
        return int(substr) >= 1 and int(substr) <= 26
    
    def rec(self,A, memo):
        if(A in memo):
            return memo[A]
        if(len(A) == 0):
            return 1
        if(A[0] == '0'):
            return 0
        if(len(A) == 1):
            return 1
 
        ans = 0
        if(self.isValid(A[0])):
            ans += self.rec(A[1:len(A)], memo)
        if(self.isValid(A[0:2])):
            ans += self.rec(A[2:len(A)], memo)
        memo[A] = ans
        return ans
        
    # @param A : string
    # @return an integer
    def numDecodings(self, A):
        return self.rec(A, {})
