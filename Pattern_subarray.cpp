#include<iostream>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallest(vector<int> v,int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int currEle=v[i];
        while(s.top()!=-1 && v[s.top()]>=currEle)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallest(vector<int> v,int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        int currEle=v[i];
        while(s.top()!=-1 && v[s.top()]>=currEle)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int computeArea(vector<int> v,int m)
{
    vector<int> next(m);
    vector<int>prev(m);
    int area=INT_MIN;
    next=nextSmallest(v,m);
    prev=prevSmallest(v,m);
    for(int i=0;i<m;i++)
    {
        int length=v[i];
        if(next[i]==-1)
        {
            next[i]=m;
        }
        int width=next[i]-prev[i]-1;
        if(length==width) // for square checking
        {
        int new_area=length*width;
        area=max(new_area,area);
        }
    }
    return area;    
}

int maximalAreaOfSubMatrixOfAll1_square(vector<vector<int>> &mat, int n, int m){
    int area=computeArea(mat[0],m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]!=0)
            {
                mat[i][j]+=mat[i-1][j];
            }
            else
            {
                mat[i][j]=0;
            }
        }
        int new_area=computeArea(mat[i],m);
        area=max(new_area,area);
    }
    return area;   
}

int main()
{
    vector<vector<int>> v={
        {1,0,1,1,1,0,0,0},
        {0,0,0,1,0,1,0,0},
        {0,0,1,1,1,0,0,0},
        {0,0,1,1,1,0,1,0},
        {0,0,1,1,0,1,1,1},
        {0,1,0,1,0,1,1,0},
        {0,1,0,1,1,0,1,0},
        {0,0,0,1,1,1,1,0}
    };
    
    int row=8;
    int col=8;
    int largestArea=maximalAreaOfSubMatrixOfAll1_square(v,row,col);
    cout<<" Area of the largest Square of black is :"<<largestArea;
    return 0;
}

