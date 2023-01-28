class Solution {
public:
    int m, n;
    bool insideGrid(int i, int j){
        if(i >=0 && i < m){
            if(j >=0 && j < n){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int srcColor = image[sr][sc];
        
        int r[] = {0, 0, 1, -1};
        int c[] = {1, -1, 0, 0};

        vector<vector<int>> isColor(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        isColor[sr][sc] = 1;
        image[sr][sc] = color;
    
        
        while(!q.empty()){
            pair<int, int> p;
            p = q.front();
            q.pop();
        
            int i = p.first;
            int j = p.second;
            for(int k = 0; k < 4; k++){
                if(insideGrid(i+r[k], j+c[k]) && isColor[i+r[k]][j+c[k]] == 0 && image[i+r[k]][j+c[k]] == srcColor){
                    isColor[i+r[k]][j+c[k]] = 1;
                    image[i+r[k]][j+c[k]] = color;
                    q.push({i+r[k], j+c[k]});
                }
            }


        }

        return image;
    }
};