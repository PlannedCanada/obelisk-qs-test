A test problem for the solver of obelisk-backend. Move testdata1.cpp in to the folder with the other
obelisk files and compile with:

g++ testdata1.cpp obelisk-quadratic-solve.cpp -g -lClp -lCoinUtils -lClpSolver -lpqxx -lopenblas -o qs-test