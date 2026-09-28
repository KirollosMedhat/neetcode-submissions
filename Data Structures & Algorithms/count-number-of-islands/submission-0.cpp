class Solution {
public:



    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        stack<pair<int,int>> myStack;

        int rows = grid.size();
        int columns = grid[0].size();
        
        int currentRow = -1;
        int currentColumn = -1;

        int res = 0; 

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == '1'){
                    currentRow = i;
                    currentColumn = j;
                    myStack.push({currentRow, currentColumn});
                    grid[currentRow][currentColumn] = '0';
                    while(!myStack.empty()){
                        pair<int,int> top = myStack.top();

                        myStack.pop();

                        if(top.first - 1 >= 0 && grid[top.first - 1][top.second] == '1') {
                            myStack.push({top.first - 1, top.second});
                            grid[top.first - 1][top.second] = '0';
                        }

                        if( top.first + 1 < rows && grid[top.first + 1][top.second] == '1'){
                            myStack.push({top.first + 1, top.second});
                            grid[top.first + 1][top.second] = '0';
                        }

                        if(top.second - 1 >= 0 && grid[top.first][top.second - 1] == '1'){
                            myStack.push({top.first, top.second - 1});
                            grid[top.first][top.second - 1] = '0';
                        } 
                        if(top.second + 1 < columns && grid[top.first][top.second + 1] == '1') {
                            myStack.push({top.first, top.second + 1});
                            grid[top.first][top.second + 1] = '0';
                        }
                    }
                    res++;
                }
            }
        }

        return res;
    }
};
