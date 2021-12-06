/*******************************************************************************
 * Name    : waterjugpuzzle.cpp
 * Author  : Pramukh Nadig
 * Date    : 10/17/2021
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

// Struct to represent state of water in the jugs.
struct State {
    int a, b, c;
    string directions;
    State *parent;

    State(int _a, int _b, int _c, string _directions) :
        a{_a}, b{_b}, c{_c}, directions{_directions}, parent{nullptr} { }
    
    State(int _a, int _b, int _c, string _directions, State *par) :
        a{_a}, b{_b}, c{_c}, directions{_directions}, parent{par} { }

    // String representation of state in tuple form.
    string to_string() {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }
};

int pourChecker(int max, int x){
    int m;
    m = x >= max ? max : x;
    
    return m;
}



string printParents(State state){
	if(state.parent != NULL){
		return printParents(*state.parent) + state.directions + " " + state.to_string() + "\n";
	}
	return state.directions + " " + state.to_string() + "\n";
}


string waterJugPuzzle(int a, int b, int c, int aGoal, int bGoal, int cGoal){
	State *state = new State (0, 0, c, "Initial state.");

	queue<State> *q = new queue<State>;
	q->push(*state);
	State *r;
	vector<vector<State*>> visited(a+1 , vector<State*>((b+1),NULL));
	while(q->empty() == false){


		r = new State(q->front());
		q->pop();
		if(r->a == aGoal && r->b == bGoal && r->c == cGoal){
			cout << printParents(*r);
			for(int i = 0; i <= a; i++){
				for(int j = 0; j<=b; j++){
					r = visited[i][j];
				}
			}

			return "";
		}

        else if(visited[r->a][r->b] == NULL){
            visited[r->a][r->b] = r;

            int pour, maxPoured;
            string flag;
            
            if(r->a != a){
				maxPoured = a - r->a;
				pour = 0;
				if(r->c != 0){
					pour = pourChecker(maxPoured, r->c);
				}
				if(pour == 1){
					flag = "";
				}
				else{
                    flag = "s";
				}
					q->push(State(r->a + pour, r->b, r->c - pour, "Pour " + to_string(pour)+ " gallon" + flag + " from C to A.", r));
				
				pour = 0;
				if(r->b != 0){
					pour = pourChecker(maxPoured, r->b);
				}

				if(pour == 1){
					flag = "";
				}
				else{
                    flag = "s";
				}

					q->push(State(r->a + pour, r->b - pour, r->c, "Pour " + to_string(pour) + " gallon" + flag + " from B to A.", r));

			}


            if(r->b != b){
				maxPoured = b - r->b;
				pour = 0;
				if(r->c != 0){
					pour = pourChecker(maxPoured, r->c);
				}
				if(pour == 1){
					flag = "";
				}
				else{
                    flag = "s";
				}
					q->push(State(r->a, r->b + pour, r->c - pour, "Pour " + to_string(pour) + " gallon" + flag + " from C to B.", r));
				
				pour = 0;
				if(r->a != 0){
					pour = pourChecker(maxPoured, r->a);
				}
				if(pour == 1){
					flag = "";
				}
				else{
                    flag = "s";
				}
					q->push(State(r->a - pour, r->b + pour, r->c, "Pour " + to_string(pour) + " gallon" + flag + " from A to B.", r));
				
			}
			if(r->c != c){
				maxPoured = c - r->c;
				pour = 0;
				if(r->b != 0){
					pour = pourChecker(maxPoured, r->b);
				}
				if(pour == 1){
					flag = "";
				}
				else{
                    flag = "s";
				}
					q->push(State(r->a, r->b - pour, r->c + pour, "Pour " + to_string(pour) + " gallon" + flag + " from B to C.", r));
				
				pour = 0;
				if(r->a != 0){
					pour = pourChecker(maxPoured, r->a);
				}
				if(pour == 1){
					flag = "";
				}
				else{
                    flag = "s";
				}
					q->push(State(r->a - pour, r->b, r->c + pour, "Pour " + to_string(pour) + " gallon" + flag + " from A to C.", r));
				
        }


    }

}
    return "No solution.";
}


