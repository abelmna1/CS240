#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Tree.h"
#include "ThreeAryTree.h"
#include <sys/time.h>
#include <fcntl.h>

using namespace std;


int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}
/* insert, remove, and find return bools, so we just print the return value every time we do one of these operations. So, a 1 indicates successful insert, remove, or find, while 0 indicates failure (which is sometimes passing the specific test) To test display(), we simply print our tree out multiple times throughout the tests.*/

int main(){
	Tree<int> unbalancedTree, balancedTree2;
        //struct timeval tvDiff, tvStart, tvEnd;

	cout << "==========Tests for BST==========" << endl << endl;

	Tree<int> tree;
	cout << "Printing an empty tree: " << endl;
	tree.display();
	cout << "Test finding an element that isn't in the tree: " << endl;
	cout << "Find 4: " <<  tree.find(4) << endl;
        cout << "Insert 5: " << tree.insert(5) << endl;
        cout << "Insert 10: " << tree.insert(10) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
        cout << "Insert 3: " << tree.insert(3) << endl;
	cout << "Insert 5: " << tree.insert(5) << endl;
	cout << "Printing the tree: " << endl;
        tree.display();
	cout << "Test finding an element that is in the tree: " << endl;
        cout << "Find 5: " << tree.find(5) << endl;
	cout << "Insert 7: " << tree.insert(7) << endl;
	cout << "Insert 11: " << tree.insert(11) << endl;
	cout << "Insert 6: " << tree.insert(6) << endl;
	cout << "Insert 8: " << tree.insert(8) << endl;
	cout << "Insert 9: " << tree.insert(9) << endl;
	cout << "Insert 4: " << tree.insert(4) << endl;
	cout << "Insert 2: " << tree.insert(2) << endl;
	cout << "Insert 1: " << tree.insert(1) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing an element, which is a right child, that has no children: " << endl;
	cout << "Remove 9: " << tree.remove(9) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing an element, which is a left child, that has no children: " << endl;
	cout << "Remove 6: " << tree.remove(6) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing an element, which is a left child, that has one right child: " << endl;
	cout << "Remove 7: " << tree.remove(7) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing an element, which is a right child, that has one right child: " << endl;
	cout << "Remove 11: " << tree.remove(11) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing an element, which is a left child, that has one left child: " << endl;
	cout << "Remove 2: " << tree.remove(2) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Insert 12: " << tree.insert(12) << endl;
	cout << "Insert 13: " << tree.insert(13) << endl;
	cout << "Insert 15: " << tree.insert(15) << endl;
	cout << "Insert 11: " << tree.insert(11) << endl;
	cout << "Test removing an element, which is a left child, that has two children: " << endl;
	cout << "Remove 10: " << tree.remove(10) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Insert 9: " << tree.insert(9) << endl;
	cout << "Insert 10: " << tree.insert(10) << endl;
	cout << "Insert 7: " << tree.insert(7) << endl;
	cout << "Test removing an element, which is a right child, that has two children: " << endl;
	cout << "Remove 11: " << tree.remove(11) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing the root, which has two children: " << endl;
	cout << "Remove 5: " << tree.remove(5) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Remove 1: " << tree.remove(1) << endl;
	cout << "Remove 3: " << tree.remove(3) << endl;
	cout << "Remove 4: " << tree.remove(4) << endl;
	cout << "Remove 7: " << tree.remove(7) << endl;
	cout << "Remove 8: " << tree.remove(8) << endl;
	cout << "Remove 9: " << tree.remove(9) << endl;
	cout << "Remove 10: " << tree.remove(10) << endl;
	cout << "Remove 12: " << tree.remove(12) << endl;
	cout << "Remove 13: " << tree.remove(13) << endl;
	cout << "Remove 15: " << tree.remove(15) << endl;
	cout << "Printing the empty tree: " << endl;
	tree.display();
	cout << "Insert 10: " << tree.insert(10) << endl;
	cout << "Test removing the root, which has no children: " << endl;
	cout << "Remove 10: " << tree.remove(10) << endl;
	cout << "Printing the empty tree: " << endl;
	tree.display();
	cout << "Insert 10: " << tree.insert(10) << endl;
	cout << "Insert 11: " << tree.insert(11) << endl;
	cout << "Insert 15: " << tree.insert(15) << endl;
	cout << "Test removing the root, which has one right child: " << endl;
	cout << "Remove 10: " << tree.remove(10) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Remove 11: " << tree.remove(11) << endl;
	cout << "Remove 15: " << tree.remove(15) << endl;
	cout << "Printing the empty tree: " << endl;
	tree.display();
	cout << "Insert 10: " << tree.insert(10) << endl;
	cout << "Insert 5: " << tree.insert(5) << endl;
	cout << "Insert 8: " << tree.insert(8) << endl;
	cout << "Insert 6: " << tree.insert(6) << endl;
	cout << "Insert 9: " << tree.insert(9) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();
	cout << "Test removing the root, which has one left child: " << endl;
	cout << "Remove 5: " << tree.remove(5) << endl;
	cout << "Printing the tree: " << endl;
	tree.display();

	cout << "==========Measuring runtime complexities of methods on balanced v.s. unbalanced BST==========" << endl << endl;
//		===========Timing 100,000 elements in unbalanced tree==================
   /*    gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 100000; i++)
         unbalancedTree.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 100,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 100000; i++)
         unbalancedTree.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 100,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 99999; i >= 0; i--)
         unbalancedTree.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 100,000 elements from unbalanced : " , &tvDiff);
      
 // ===========Timing 75,000 elements on unbalanced tree===================
 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 75000; i++)
         unbalancedTree.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 75,000 elements to unbalanced : " , &tvDiff);


       gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 75000; i++)
         unbalancedTree.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 75,000 elements in unbalanced : " , &tvDiff);


       gettimeofday(&tvStart, NULL);
       for(int i = 74999; i >= 0; i--)
         unbalancedTree.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 75,000 elements from unbalanced : " , &tvDiff);


//		==============Timing 50,000 elements on unbalanced tree================

       gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 50000; i++)
         unbalancedTree.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 50,000 elements to unbalanced : " , &tvDiff);


       gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 50000; i++)
         unbalancedTree.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 50,000 elements in unbalanced : " , &tvDiff);


       gettimeofday(&tvStart, NULL);
       for(int i = 49999; i >= 0; i--)
         unbalancedTree.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 50,000 elements from unbalanced : " , &tvDiff); 
   

//		==============Timing 25,000 elements on unbalanced tree================


       gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 25000; i++)
         unbalancedTree.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 25,000 elements to unbalanced : " , &tvDiff);


       gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 25000; i++)
         unbalancedTree.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 25,000 elements in unbalanced : " , &tvDiff);
    

       gettimeofday(&tvStart, NULL);
       for(int i = 24999; i >= 0; i--)
         unbalancedTree.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 25,000 elements from unbalanced : " , &tvDiff); 



//		==============Timing 125,000 elements on balanced tree================
    
    // int array[125000];
     // for(int i = 0; i < 125000; i++)
     //     array[i] = i;
    // int start = 0;
    // int end = 124999;
       
	//gettimeofday(&tvStart, NULL);
  //      balancedTree2.setRoot(NULL);
       // balancedTree2.balancedTree( (*(balancedTree2.getRoot())), array, start, end);
        //gettimeofday(&tvEnd, NULL);
        //timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        //timeval_print("insert 125,000 elements to balanced : " , &tvDiff); 


	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 125000; i++)
         balancedTree2.insert(rand() % 200000);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 125,000 elements to balanced : " , &tvDiff);





	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 125000; i++)
         balancedTree2.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 125,000 elements in balanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 124999; i >= 0; i--)
         balancedTree2.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 125,000 elements from balanced : " , &tvDiff);*/
          
         

	cout << "==========Tests for ThreeAryTree==========" << endl << endl;
	ThreeAryTree<int> tree1;
	cout << "Printing an empty tree: " << endl;
	tree1.display();
	cout << "Insert 10: " << tree1.insert(10) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 10: " << tree1.remove(10) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 10: " << tree1.insert(10) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();

	cout << "Insert 10: " << tree1.insert(10) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	
	cout << "Insert 5: " << tree1.insert(5) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 5: " << tree1.remove(5) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 5: " << tree1.insert(5) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();

	cout << "Insert 8: " << tree1.insert(8) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 8: " << tree1.remove(8) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 8: " << tree1.insert(8) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();

	cout << "Insert 15: " << tree1.insert(15) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 15: " << tree1.remove(15) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 15: " << tree1.insert(15) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();


	cout << "Insert 12: " << tree1.insert(12) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 12: " << tree1.remove(12) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 12: " << tree1.insert(12) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();


	cout << "Insert 14: " << tree1.insert(14) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 14: " << tree1.remove(14) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 14: " << tree1.insert(14) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();


	cout << "Insert 39: " << tree1.insert(39) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 39: " << tree1.remove(39) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 39: " << tree1.insert(39) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();

	cout << "Insert 22: " << tree1.insert(22) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Remove 22: " << tree1.remove(22) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 22: " << tree1.insert(22) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();

	cout << "Remove 39: " << tree1.remove(39) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << "Insert 39: " << tree1.insert(39) << endl;
	cout << "Printing the tree: " << endl;
	tree1.display();


	cout << "Find 10: " << tree1.find(10) << endl;
	cout << "Find 5: " << tree1.find(5) << endl;
	cout << "Find 8: " << tree1.find(8) << endl;
	cout << "Find 15: " << tree1.find(15) << endl;
	cout << "Find 12: " << tree1.find(12) << endl;
	cout << "Find 14: " << tree1.find(14) << endl;
	cout << "Find 39: " << tree1.find(39) << endl;
	cout << "Find 20: " << tree1.find(20) << endl;
	cout << "Find 35: " << tree1.find(35) << endl;
	cout << "Find 0: " << tree1.find(0) << endl;
	cout << "Find 99: " << tree1.find(99) << endl;

	int i;

	cout << endl << "Inserting 100 random elements to the tree: " << endl;
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		cout << "Insert Random number: " << tree1.insert(rand() % 100) << endl;
	}
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << endl << "Attempting to remove numbers 1 to 100 from the tree" << endl;
	for (i = 0; i < 100; i++) {
		cout << "Remove " << i << ": " << tree1.remove(i) << endl;
	}	

	Tree<int> tree2;
	tree2.insert(50);
	cout << endl << "Inserting 100 random elements to the tree: " << endl;
	for (i = 0; i < 100; i++) {
		cout << "Insert Random number: " << tree2.insert(rand() % 100) << endl;
	}
	cout << "Printing the tree: " << endl;
	tree1.display();
	cout << endl << "Attempting to remove numbers 1 to 100 from the tree" << endl;
	for (i = 0; i < 100; i++) {
		cout << "Remove " << i << ": " << tree2.remove(i) << endl;
	}	
	cout << "Printing the tree: " << endl;
	tree2.display();

	cout << "==========Measuring runtime complexities of methods on balanced v.s. unbalanced 3-ary Tree==========" << endl << endl;
    
  //		===========Timing 100,000 elements in unbalanced tree==================
  /*    gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 100000; i++)
         tree1.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 100,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 100000; i++)
         tree1.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 100,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 100000; i++)
         tree1.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 100,000 elements from unbalanced : " , &tvDiff); 
      
 // ===========Timing 75,000 elements on unblanced tree===================
 
   gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 75000; i++)
         tree1.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 75,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 75000; i++)
         tree1.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 75,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 75000; i++)
         tree1.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 75,000 elements from unbalanced : " , &tvDiff);





//		==============Timing 50,000 elements on unbalanced tree================

      gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 50000; i++)
         tree1.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 50,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 50000; i++)
         tree1.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 75,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 50000; i++)
         tree1.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 50,000 elements from unbalanced : " , &tvDiff);
   

//		==============Timing 25,000 elements on unbalanced tree================
 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 25000; i++)
         tree1.insert(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 25,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 25000; i++)
         tree1.find(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 25,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 25000; i++)
         tree1.remove(i);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 25,000 elements from unbalanced : " , &tvDiff);
  



// ==============Timing 125,000 elements on balanced tree================
    
    gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 125000; i++)
         tree1.insert(rand() % 200000);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 125,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 125000; i++)
         tree1.find(200001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 125,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 125000; i++)
         tree1.remove(200001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 125,000 elements from unbalanced : " , &tvDiff);            
       

// ==============Timing 250,000 elements on balanced tree================
    
    gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 250000; i++)
         tree1.insert(rand() % 500000);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 250,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 250000; i++)
         tree1.find(500001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 250,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 250000; i++)
         tree1.remove(500001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 250,000 elements from unbalanced : " , &tvDiff);  
 

 // ==============Timing 500,000 elements on balanced tree================
    
    gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 500000; i++)
         tree1.insert(rand() % 750000);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 500,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 500000; i++)
         tree1.find(750001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 500,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 500000; i++)
         tree1.remove(750001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 125,000 elements from unbalanced : " , &tvDiff);  

// ==============Timing 1,000,000 elements on balanced tree================
    
    gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 1000000; i++)
         tree1.insert(rand() % 2000000);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("insert 1,000,000 elements to unbalanced : " , &tvDiff);


	 gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 1000000; i++)
         tree1.find(2000001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("finding 1,000,000 elements in unbalanced : " , &tvDiff);



	gettimeofday(&tvStart, NULL);
       for(int i = 0; i < 1000000; i++)
         tree1.remove(2000001);  
        gettimeofday(&tvEnd, NULL);
        timeval_subtract(&tvDiff, &tvEnd, &tvStart);
        timeval_print("removing 1,000,000 elements from unbalanced : " , &tvDiff); */
	return 0;
}
  










