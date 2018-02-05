# 4-K-Mean-Clustering<br />
### CSC 323-32: Project 4 <K Mean Clustering> (C++)<br />
### Preston Peck<br />
### Due date: Nov. 1, 2016 <br />

#### **** Algorithm steps for K Mean Clustering:<br />

Step 0: Open the input file<br />
     0.1: K, numRow, numCol numPts- get from input file.<br />
     0.2: imageArray- Dynamically allocate a 2-D arrays, size numRows X numCols.<br />
     0.3: pointSet- Dynamically allocate the point set, size of numPts<br />
     0.4: Kcentroids[K]- Dynamically allocate the K centroids struct.<br />

Step 1: call loadPointSet<br />

Step 2: call assignLabel<br />

Step 3: call mapPoint2Image<br />

Step 4: call displayImage<br />

Step 5: Go thru the entire pointSet struct array to compute the centroids of the K clusters. Store  <br />
            the centroids in each Kcentroids[i], i from 1 to K.<br />

Step 6: for each point, p, in the pointSet array compute the distance, dist(p,ci), from p to the  <br />
            centroids of each Kcentroids[i], i = 1 to K<br />
     6.1: min_i <-- determine which dist(p,ci) is minimum<br />
     6.2: if min_i is not the same as p's old label change p's label to min_i and set changeLabel to <br />
true<br />

Step 7: repeat step 6 until all points in pointSet are process.<br />
 
Step 8: repeat step 3 to step 7 until no point changes its label.<br />

Step 9: Output the info of pointSet to Output-1 file.<br />
 
### Input<br />
4<br />
90<br />
80 80<br />
18 58<br />
21 52<br />
19 46<br />
13 46<br />
16 38<br />
11 36<br />
11 58<br />
14 42<br />
10 42<br />
10 41<br />
10 44<br />
11 54<br />
9 57<br />
10 52<br />
21 41<br />
8 46<br />
12 38<br />
8 35<br />
10 38<br />
13 49<br />
8 46<br />
20 55<br />
21 53<br />
11 48<br />
11 53<br />
14 57<br />
9 49<br />
16 39<br />
10 35<br />
13 51<br />
39 14<br />
38 9<br />
29 20<br />
38 11<br />
27 21<br />
41 24<br />
29 23<br />
36 10<br />
37 19<br />
29 10<br />
35 26<br />
36 20<br />
35 23<br />
34 18<br />
37 24<br />
38 56<br />
37 60<br />
47 54<br />
45 48<br />
44 60<br />
39 51<br />
43 52<br />
38 61<br />
45 63<br />
44 55<br />
44 47<br />
41 66<br />
40 55<br />
49 52<br />
44 53<br />
59 30<br />
61 36<br />
65 34<br />
61 38<br />
66 25<br />
58 39<br />
66 39<br />
68 30<br />
61 28<br />
62 25<br />
62 30<br />
64 20<br />
59 24<br />
63 28<br />
61 30<br />
69 24<br />
69 32<br />
71 30<br />
70 38<br />
57 39<br />
58 43<br />
66 28<br />
64 21<br />
64 39<br />
63 41<br />
67 44<br />
63 29<br />
61 21<br />
65 43<br />
63 24<br />

### Output<br />
18 58 1<br />
21 52 1<br />
19 46 1<br />
13 46 1<br />
16 38 1<br />
11 36 1<br />
11 58 1<br />
14 42 1<br />
10 42 1<br />
10 41 1<br />
10 44 1<br />
11 54 1<br />
9 57 1<br />
10 52 1<br />
21 41 1<br />
8 46 1<br />
12 38 1<br />
8 35 1<br />
10 38 1<br />
13 49 1<br />
8 46 1<br />
20 55 1<br />
21 53 1<br />
11 48 1<br />
11 53 1<br />
14 57 1<br />
9 49 1<br />
16 39 1<br />
10 35 1<br />
13 51 1<br />
39 14 4<br />
38 9 4<br />
29 20 4<br />
38 11 4<br />
27 21 4<br />
41 24 4<br />
29 23 4<br />
36 10 4<br />
37 19 4<br />
29 10 4<br />
35 26 4<br />
36 20 4<br />
35 23 4<br />
34 18 4<br />
37 24 4<br />
38 56 2<br />
37 60 2<br />
47 54 2<br />
45 48 2<br />
44 60 2<br />
39 51 2<br />
43 52 2<br />
38 61 2<br />
45 63 2<br />
44 55 2<br />
44 47 2<br />
41 66 2<br />
40 55 2<br />
49 52 2<br />
44 53 2<br />
59 30 3<br />
61 36 3<br />
65 34 3<br />
61 38 3<br />
66 25 3<br />
58 39 3<br />
66 39 3<br />
68 30 3<br />
61 28 3<br />
62 25 3<br />
62 30 3<br />
64 20 3<br />
59 24 3<br />
63 28 3<br />
61 30 3<br />
69 24 3<br />
69 32 3<br />
71 30 3<br />
70 38 3<br />
57 39 3<br />
58 43 3<br />
66 28 3<br />
64 21 3<br />
64 39 3<br />
63 41 3<br />
67 44 3<br />
63 29 3<br />
61 21 3<br />
65 43 3<br />
63 24 3<br />





                                   2          1                                 
                                                 3       1                      
                                   1  3  21 3       2                           
                                    2           4    14   3                     
                                      1                                         
                                              4  4 2                            
                                          4              2                      
                                                                                
                                      14                                        
                                                                                
                                                          1                     
                                              3                                 
                                                       2                        
                                         3          23                          
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                     3                                                          
                                                                                
          4         1  1                                                        
                                                                                
                                                                                
                                                                                
                                                                                
                  4                                                             
                       3  1                                                     
          2         2                                                           
                   3    1                                   3                   
         4 2                                            2    1                  
              3                                    3                            
                                                       2                        
                        4                                         1             
                                                                                
                                                    4                           
                                               4     4 3    2                   
                                                1              2                
                                                                                
                                                      4                         
                                                                                
                                                    3                           
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                       4                                        
                                       2   1                                    
                        1     1                                                 
                                                                                
                     4      1 3     2 4                                         
                         2    3                                                 
                        2   23           1                                      
                    43                 4                                        
                                  3        1                                    
                         1  2          3                                        
                                            2                                   
                              4                                                 
                        4       1                                               
                                      3                                         
                              2   
-------------------------------------------------------------------------------
                                   1          1                                 
                                                 1       1                      
                                   1  1  11 1       1                           
                                    1           1    11   1                     
                                      1                                         
                                              1  1 1                            
                                          1              1                      
                                                                                
                                      11                                        
                                                                                
                                                          1                     
                                              1                                 
                                                       1                        
                                         1          11                          
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                     4                                                          
                                                                                
          4         4  4                                                        
                                                                                
                                                                                
                                                                                
                                                                                
                  4                                                             
                       4  4                                                     
          4         4                                                           
                   4    4                                   1                   
         4 4                                            2    2                  
              4                                    2                            
                                                       2                        
                        4                                         2             
                                                                                
                                                    2                           
                                               2     2 2    2                   
                                                2              2                
                                                                                
                                                      2                         
                                                                                
                                                    2                           
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                       3                                        
                                       3   3                                    
                        4     3                                                 
                                                                                
                     4      3 3     3 3                                         
                         4    3                                                 
                        4   33           3                                      
                    44                 3                                        
                                  3        3                                    
                         3  3          3                                        
                                            3                                   
                              3                                                 
                        3       3                                               
                                      3                                         
                              3              
-------------------------------------------------------------------------------
                                   1          1                                 
                                                 1       1                      
                                   1  1  11 1       1                           
                                    1           1    11   1                     
                                      1                                         
                                              1  1 1                            
                                          1              1                      
                                                                                
                                      11                                        
                                                                                
                                                          1                     
                                              1                                 
                                                       1                        
                                         1          11                          
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                     4                                                          
                                                                                
          4         4  4                                                        
                                                                                
                                                                                
                                                                                
                                                                                
                  4                                                             
                       4  4                                                     
          4         4                                                           
                   4    4                                   2                   
         4 4                                            2    2                  
              4                                    2                            
                                                       2                        
                        4                                         2             
                                                                                
                                                    2                           
                                               2     2 2    2                   
                                                2              2                
                                                                                
                                                      2                         
                                                                                
                                                    2                           
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                       3                                        
                                       3   3                                    
                        3     3                                                 
                                                                                
                     3      3 3     3 3                                         
                         3    3                                                 
                        3   33           3                                      
                    33                 3                                        
                                  3        3                                    
                         3  3          3                                        
                                            3                                   
                              3                                                 
                        3       3                                               
                                      3                                         
                              3                                                 
