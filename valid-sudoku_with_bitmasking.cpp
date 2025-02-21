//https://leetcode.com/problems/valid-sudoku/submissions/1550737637/

// done with bitmasking is a important question medium 
//O(n^2) time and O(n) space

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int maskrow[9]={0},maskcol[9]={0},maskbox[9]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'1';
                if(maskrow[i]&(1<<num) || maskcol[j]&(1<<num) || maskbox[(i/3)*3+(j/3)]&(1<<num))
                    return false;
                maskrow[i]|=(1<<num);
                maskcol[j]|=(1<<num);
                maskbox[(i/3)*3+(j/3)]|=(1<<num);
            }
        }
        return true;
    }
};
