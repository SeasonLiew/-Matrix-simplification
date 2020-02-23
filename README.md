# Simplification of n*n matrix and caculation of its determinant
this prgm was inspired while learning the gauss elinimiation of linear algebra. it uses the general elimination procedure to simplify a matrix and calculate its determinant as well.
e.g. the matrix saved as a 2d array as follow
```
 * * * * * * * * * * * *
|2.00 -1.00 -1.00 5.00 
|1.00 1.00 -2.00 1.00 
|4.00 -6.00 1.00 5.00 
|3.00 -2.00 4.00 1.00 
 * * * * * * * * * * * *
```
the final result of simplicication
```
 * * * * * * * * * * * *
|2.00 -1.00 -1.00 5.00 
|  0 1.50 -1.50 -1.50 
|  0   0 -1.00 -9.00 
|  0   0   0 -52.00 
 * * * * * * * * * * * *
 ```

the determinant is 156.00
