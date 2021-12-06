/*******************************************************************************
 * Name    : shortestpaths.cpp
 * Author  : Pramukh Nadig
 * Version : 1.0
 * Date    : December 6, 2021
 * Description : Computes the shortest path using Floyd's algorithm.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <bits/stdc++.h>


using namespace std;


const long INF = numeric_limits<long>::max();

int len(long num){
	return (num == 0) ? 1 : log10(num) + 1;

}

    string getPathH(vector<vector<long>> intervertices, int i, int j){
        if (!(intervertices[i][j] == INF)){
            return getPathH(intervertices, i, intervertices[i][j]) + getPathH(intervertices, intervertices[i][j], j);
        }else{
            string answer = "";
            answer +=  (j + 'A'); 
            answer += " -> ";
            return answer;
        }
    }

string getPath(vector<vector<long>> intervertices, int i, int j){
    string answer = "";
    answer +=  (i + 'A'); 
    answer += " -> " +  getPathH(intervertices, i, intervertices[i][j]) + getPathH(intervertices, intervertices[i][j], j);

    answer = answer.substr(0, answer.length()-4);

    return answer;

}

/** 
 * Displays the matrix on the screen formatted as a table. 
 */ 
void display_table(vector<vector<long>> matrix, const string &label, const bool use_letters = false) {
    cout << label << ":" << endl;
    long max_val = 0;
    for(size_t i = 0; i < matrix.size(); ++i){
        for(size_t j = 0; j < matrix.size(); ++j){
            long cell = matrix[i][j];
            if(cell < INF && cell > max_val){
                max_val = matrix[i][j];
            }
        }
    }

    int max_cell_width = use_letters ? len(max_val) : len(max(static_cast<long>(matrix.size()), max_val)); 
    cout << ' ';
    for(size_t j = 0; j < matrix.size(); j++){
        cout << setw(max_cell_width + 1) << static_cast<char>(j + 'A');
    }
    cout << endl;
    for(size_t i = 0; i < matrix.size(); i++){
        cout << static_cast<char>(i + 'A');
        for(size_t j = 0; j < matrix.size(); j++){
            cout << " " << setw(max_cell_width);
            if(matrix[i][j] == INF){
                cout << "-";
            }else if(use_letters){
                cout << static_cast<char>(matrix[i][j] + 'A');
            }else{
                cout << matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}
    //Print out all the edges and their distance to every other edge in the matrix
    void floyd(int vertices, vector<vector<long>> paths, vector<vector<long>> intermediateVertices){
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                if (paths[i][j] == 0){
                    cout << (char)(i + 'A') << " -> " << (char)(j+'A') << ", distance: " << paths[i][j] << ", path: " << (char)(i + 'A') << endl;
                }
                else if (paths[i][j] == INF){
                    cout << (char)(i + 'A') << " -> " << (char)(j+'A') << ", distance: " << "infinity" << ", path: " << "none"<< endl;
                }
                else if (intermediateVertices[i][j] == INF){
                    cout << (char)(i + 'A') << " -> " << (char)(j+'A') << ", distance: " << paths[i][j] << ", path: " << (char)(i + 'A') << " -> " << (char)(j+'A') << endl;
                }
                else{
                    cout << (char)(i + 'A') << " -> " << (char)(j+'A') << ", distance: " << paths[i][j] << ", path: " << getPath(intermediateVertices,i,j) << endl;
                }

            }
        
        }
    }

int main(int argc, char *argv[]) {

    
    if (argc != 2){
        cout << "Usage: ./shortestpaths <filename>";
        return 1;
    }

    ifstream file (argv[1]);

    if (!(file)){
        cerr << "Error: Cannot open file " << "'" << argv[1] << "'.";
        return 1;
    }

        istringstream iss;
        string line;
        int vertices;

        getline (file,line);
        iss.str(line);
        if(!(iss >> vertices)){
            cerr << "Error: Invalid number of vertices " << "'" <<  line << "'" << " on line 1.";
            return 1;
        }


    if ((vertices > 26) || (vertices < 1)){
        cerr << "Error: Invalid number of vertices " << "'" <<  line << "'" << " on line 1.";
        return 1;
    }
    vector<vector<long> > matrix;

    // fill matrix with INF
    matrix.resize(vertices, vector<long>(vertices, INF));

    //distance from every edge to itself is 0
    for (int i = 0; i < vertices; i++){
        matrix[i][i] = 0;
    }

    int lineNum = 1;
    int weight;


        try{
            while ( getline(file,line) ){
                lineNum++;
                iss.clear();
                iss.str(line);

                //temp vector to hold the words on each line
		        vector<string> tempVector(istream_iterator<string> { iss }, istream_iterator<string>());

        
                if (tempVector.size() != 3){ 
                    cerr << "Error: Invalid edge data " << "'" <<  line << "'" << " on line " << lineNum << "." << endl;
                    return 1;
                }

                if (tempVector.at(0).length() > 1 || (tempVector.at(0).at(0) - 'A') >= vertices || (tempVector.at(0).at(0) - 'A') < 0){             
                    cerr << "Error: Starting vertex " << "'" << tempVector[0] << "'" << " on line " << lineNum << " is not among valid values " << "A-" << (char)('A'+vertices - 1) << "." << endl; 
                    return 1;
                }
                if (tempVector.at(1).length() > 1 || (tempVector.at(1).at(0) - 'A') >= vertices || (tempVector.at(1).at(0) - 'A') < 0){             
                
                    cerr << "Error: Ending vertex " << "'" << tempVector[1] << "'" << " on line " << lineNum << " is not among valid values " << "A-" << (char)('A'+vertices - 1) << "." << endl; 
                    return 1;
                }
                iss.clear();
                iss.str(tempVector[2]); // get weights of edges
                if (!(iss >> weight) || weight < 1){
                    cerr << "Error: Invalid edge weight " << "'" << tempVector[2] << "'" << " on line " << lineNum << ".";
                    return 1;
                }

                //set matrix edge weights
                matrix[tempVector[0][0] - 'A'][tempVector[1][0] - 'A'] = weight;

                
            }
            file.close();
            }catch(const ifstream::failure &f) { // close try/catch block
            cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
            return 1;
        }
    
    vector<vector<long> > paths = matrix; 
    vector<vector<long> > intermediateVertices;

    //fill the matrix with INFs
    intermediateVertices.resize(vertices, vector<long>(vertices, INF));
    for (int i = 0; i < vertices; i++){
        for (int k = 0; k < vertices; k++){
            for (int j = 0; j < vertices; j++){
                if(paths[i][j] == INF || paths[k][i] == INF){
                    continue;
                }if (paths[k][i] + paths[i][j] < paths[k][j]){
                    paths[k][j] = paths[k][i] + paths[i][j];
                    intermediateVertices[k][j] = i;
                }
            }
        }
    }

    display_table(matrix, "Distance matrix", false);
    display_table(paths, "Path lengths", false);
    display_table(intermediateVertices, "Intermediate vertices", true);
    

    floyd(vertices, paths, intermediateVertices);
    return 0;
}
