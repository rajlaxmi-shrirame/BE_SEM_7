class Item:
    def __init__(self,profit,weight):
        self.profit=profit
        self.weight=weight

def Knapsack(arr,n,w):
    dp=[[0]*(w+1) for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(w+1):
            if arr[i-1].weight<=j:
                dp[i][j]=max(arr[i-1].profit+dp[i-1][j-arr[i-1].weight],dp[i-1][j])
            else:
                dp[i][j]=dp[i-1][j]
    return dp[n][w]
            
    
arr=[]    
n=int(input('Enter no of items : '))
for _ in range(n):
    p,w=map(int,input('Enter profit and weight (p,w) : ').split(','))
    arr.append(Item(p,w))
w=int(input('Enter maximum weight capacity : '))
print('Maximum Profit : ',Knapsack(arr, n, w))