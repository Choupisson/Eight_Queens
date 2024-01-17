# Eight_Queens_Problems

## Le problème des 8 reines
Le but du problème des 8 reines est de placer 8 reines d’un jeu d’échecs sur un échiquier de
8x8 cases sans que les reines ne puissent se menacer mutuellement, conformément aux règles du
jeu d’échecs. Par conséquent, deux reines ne devraient jamais partager la même rangée, colonne, ou
diagonale.
Comme chaque reine occupe une rangée différente, on peut nommer une reine par la rangée
qu’elle occupe. On représente alors chaque solution par un tableau d’entiers solution de taille 8.
Par exemple, si solution[2] = 4 alors dans la troisième rangée, une reine est placé sur la cinquième
colonne.
L’algorithme de positionner les 8 reines est le suivant. On considère tout d’abord la première
rangée de l’échiquier. Pour chaque position dans cette rangée, on cherche s’il est possible d’y mettre
une reine, sans que cela mène à une impasse. Ensuite, pour chaque position convenable de la reine
dans la première rangée, on appliquera la même méthode à la seconde rangée : pour chaque position
dans cette seconde rangée, on cherche s’il est possible d’y mettre une reine sans que cela mêne à
une impasse. Et ainsi de suite, jusqu’à la dernière rangée. On peut résoudre le problème de façon
itérative avec 8 boucles imbriquées, une pour chaque rangée. Nous allons le résoudre de manière plus
succincte, et récursive.
1. Ecrire une procédure printSolution(solution, size) qui affiche à l’écran le contenu de l’échiquier
(i.e. les cases vides et les cases occupées) en fonction de la position des reines.
2. Ecrire une procédure saveSolution(solution, size, fileName) qui permet d’enregistrer chaque
solution dans un fichier dont le nom est passé en paramètre.
3. Ecrire une fonction queenIsSafe(solution, x, y) qui renvoie vrai s’il est possible de placer une
reine dans la case (x, y), où y est la rangée, x est la colonne. Cette fonction prend en compte
pour cela les pièces déjà positionnées et stockées dans le tableau solution.
1
4. Ecrire une procédure search(solution, size, y, fileName) qui recherche, et enregistre, toutes les
solutions à partir de la rangée y de l’échiquier. Cette fonction prend en argument un tableau
solution ainsi que sa taille size, un entier y représentant la rangée considérée, et une chaîne
de caractères f ileN ame indiquant le nom du fichier à créer pour stocker les solutions trouvées
(92). Pour chaque position dans la rangée y, cet algorithme cherche récursivement celles qui
sont acceptables en considérant celles qui ont été trouvées dans les rangées précédentes (i.e.
< y).
5. Optimiser la fonction queenIsSafe(solution, x, y) par rapport à cette stratégie.
## Les variantes du problème des 8 reines
Il existe plusieurs variantes au problème des 8 reines. Dans ces variantes, il ne s’agit plus de placer
8 reines mais 14 fous, 16 rois ou 32 cavaliers. Dans la suite, vous devrez développer des algorithmes
pour résoudre ces problèmes en adaptant ceux faits précédemment.
1. Ecrire une fonction bishopIsSafe qui renvoie vrai s’il est possible de placer un fou dans la case
(x, y), où y est la rangée, x est la colonne.
2. Ecrire une fonction kingIsSafe qui renvoie vrai s’il est possible de placer un roi dans la case
(x, y), où y est la rangée, x est la colonne.
3. Ecrire une fonction knightIsSafe qui renvoie vrai s’il est possible de placer un cavalier dans
la case (x, y), où y est la rangée, x est la colonne.
4. Rendre générique votre procédure search afin de pouvoir passer en paramètre la fonction de
test, et ainsi pourvoir résoudre avec la même approche les différentes variantes du problème
des 8 reines. Pour cela, vous vous documenterez sur les pointeurs de fonctions ("function
pointers" en anglais).
