def longestPalindrome(S):
    def expand(left,right):
        while left>=0 and right<=len(S) and S[left]==S[right-1]:
            left-=1
            right+=1
        return len(S[left+1:right-1])
    
    if len(S)<2 or S==S[::-1]: return len(S)
    
    result=0
    for i in range(len(S)-1):
        result=max(result,expand(i,i+2),expand(i,i+1))
    
    return result

S=input().rstrip()
print(longestPalindrome(S))