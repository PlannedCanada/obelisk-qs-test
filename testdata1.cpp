#include "obelisk-quadratic-solve.hpp"

#include <map>

#include <cfloat>

using namespace std;

pair<int,double>* tech_matrix[6];
int constraint_cols[6] = {3,3,3,2,2,2};
double problem_rhs[6] = {0,0,0,8,5,8};
double quadratics[8] = {-0.5,0,-0.5,0,0,-0.5,0,0};
double linears[8] = {100,0,100,0,0,100,0,0};

int main() {

   tech_matrix[0] = new pair<int,double>[3];
   tech_matrix[0][0] = make_pair(0,1);
   tech_matrix[0][1] = make_pair(1,2);
   tech_matrix[0][2] = make_pair(2,-1);
   
   tech_matrix[1] = new pair<int,double>[3];
   tech_matrix[1][0] = make_pair(0,1);
   tech_matrix[1][1] = make_pair(1,1);
   tech_matrix[1][2] = make_pair(3,-1);
   
   tech_matrix[2] = new pair<int,double>[3];
   tech_matrix[2][0] = make_pair(0,2);
   tech_matrix[2][1] = make_pair(1,1);
   tech_matrix[2][2] = make_pair(4,-1);
   
   tech_matrix[3] = new pair<int,double>[2];
   tech_matrix[3][0] = make_pair(2,1);
   tech_matrix[3][1] = make_pair(5,1);
   
   tech_matrix[4] = new pair<int,double>[2];
   tech_matrix[4][0] = make_pair(3,1);
   tech_matrix[4][1] = make_pair(6,1);
   
   tech_matrix[5] = new pair<int,double>[2];
   tech_matrix[5][0] = make_pair(4,1);
   tech_matrix[5][1] = make_pair(7,1);

   quadratic_programming_problem plan_economy;

   plan_economy.problem_matrix = tech_matrix;
   plan_economy.constraint_cols = constraint_cols;
   plan_economy.rhs = problem_rhs;
   plan_economy.quadratic_coefficients = quadratics;
   plan_economy.linear_coefficients = linears;
   plan_economy.variables = 8;
   plan_economy.constraints = 6;
   
   double* solution = new double[8];
   if (plan_economy.solve(solution)) return 1;
   
   cout << "\nresult:\n";
   for (int i = 0; i < 8; i++) {
     cout << "\t" << solution[i];
   }
   
   return 0;

}