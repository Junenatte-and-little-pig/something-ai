predicates
	even(integer)
clauses
	even(0).
	even(1).
	even(A):-
		B=A-2,
		even(B).
goal
	write("input a nuber"),nl,
	readint(NM),
	even(NM).