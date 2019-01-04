domains
predicates
   teacher(symbol,symbol)
   classmate(symbol,symbol)
clauses
   classmate(li, zhang).
   teacher(wang, li).
   teacher(Z, Y):- classmate(X, Y), teacher(Z, X).
goal
   teacher(U,zhang). 
