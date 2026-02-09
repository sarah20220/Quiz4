// Note - the autograder expects this exact include for your catch code! If you use the manual catch compilation method, be sure you put this include back before submitting.
#include <catch2/catch_test_macros.hpp>

#include "GatorBST.h"

using namespace std;

// ------------------INSERT--CASES--------------------------------------------------------------------------------------

TEST_CASE("Checking insert with only right children.", "[Insert]"){
	GatorBST<string> test;

	REQUIRE(test.Insert(1, "a") == true);
	REQUIRE(test.Insert(2, "b") == true);
	REQUIRE(test.Insert(3, "c") == true);
};

TEST_CASE("Checking insert with only left children.", "[Insert]"){
	GatorBST<string> test;

	REQUIRE(test.Insert(3, "a") == true);
	REQUIRE(test.Insert(2, "b") == true);
	REQUIRE(test.Insert(1, "c") == true);
};

TEST_CASE("Checking insert allows duplicate names.", "[Insert]"){
	GatorBST<string> test;

	REQUIRE(test.Insert(1, "a") == true);
	REQUIRE(test.Insert(2, "a") == true);
};

TEST_CASE("Checking insert doesn't allow duplicate UIDs.", "[Insert]"){
	GatorBST<string> test;

	REQUIRE(test.Insert(1, "a") == true);
	REQUIRE(test.Insert(1, "b") == false);
};

// ------------------HEIGHT--CASES--------------------------------------------------------------------------------------

TEST_CASE("Checking height of a balanced tree.", "[Height]"){
	GatorBST<string> test;

	test.Insert(9, "a");
	test.Insert(7, "b");
	test.Insert(12, "c");
	test.Insert(8, "d");
	test.Insert(6, "e");
	test.Insert(10, "f");
	test.Insert(15, "g");

	REQUIRE(test.Height() == 3);
};

TEST_CASE("Checking height of a asymmetric tree.", "[Height]"){
	GatorBST<string> test;

	test.Insert(9, "a");
	test.Insert(5, "b");
	test.Insert(12, "c");
	test.Insert(6, "d");
	test.Insert(4, "e");
	test.Insert(10, "f");
	test.Insert(15, "g");
	test.Insert(7, "h");

	REQUIRE(test.Height() == 4);
};

TEST_CASE("Checking height with only left child.", "[Height]"){
	GatorBST<string> test;

	test.Insert(9, "root");
	test.Insert(7, "one");
	test.Insert(5, "two");

	REQUIRE(test.Height() == 3);
};

TEST_CASE("Checking height with only right child.", "[Height]"){
	GatorBST<string> test;

	test.Insert(9, "root");
	test.Insert(11, "one");
	test.Insert(15, "two");

	REQUIRE(test.Height() == 3);
};

TEST_CASE("Checking height of empty tree.", "[Height]"){
	GatorBST<string> test;

	REQUIRE(test.Height() == 0);
};

TEST_CASE("Checking height only root.", "[Height]"){
	GatorBST<string> test;

	test.Insert(1, "root");

	REQUIRE(test.Height() == 1);
};

// ------------------SEARCHID--CASES------------------------------------------------------------------------------------

TEST_CASE("Check SearchID with empty tree.", "[SearchID]"){
	GatorBST<string> test;

	auto SearchResult = test.SearchID(1);

	REQUIRE(SearchResult.has_value() == false);
};

TEST_CASE("Check SearchID with nonexistent ID.", "[SearchID]"){
	GatorBST<string> test;

	test.Insert(2, "a");
	test.Insert(1, "b");
	test.Insert(3, "c");

	auto SearchResult = test.SearchID(4);

	REQUIRE(SearchResult.has_value() == false);
};

TEST_CASE("Check SearchID with 1 node tree.", "[SearchID]"){
	GatorBST<string> test;

	test.Insert(1, "root");

   	REQUIRE(test.SearchID(1).value() == "root");

};

TEST_CASE("Check SearchID of every node in a 3 level tree.", "[SearchID]"){
	GatorBST<string> test;

	test.Insert(9, "a");
	test.Insert(5, "b");
	test.Insert(12, "c");
	test.Insert(6, "d");
	test.Insert(4, "e");
	test.Insert(10, "f");
	test.Insert(15, "g");
	test.Insert(7, "h");

	REQUIRE(test.SearchID(9).value() == "a");
	REQUIRE(test.SearchID(5).value() == "b");
	REQUIRE(test.SearchID(12).value() == "c");
	REQUIRE(test.SearchID(6).value() == "d");
	REQUIRE(test.SearchID(4).value() == "e");
	REQUIRE(test.SearchID(10).value() == "f");
	REQUIRE(test.SearchID(15).value() == "g");
	REQUIRE(test.SearchID(7).value() == "h");
};

// ------------------SEARCHNAME--CASES----------------------------------------------------------------------------------

TEST_CASE("SearchName in an empty tree.", "[SearchName]"){
	GatorBST<string> test;

	REQUIRE(test.SearchName("name").empty());
};

TEST_CASE("SearchName for nonexistent name.", "[SearchName]"){
	GatorBST<string> test;

	test.Insert(7, "a");
	test.Insert(3, "b");
	test.Insert(12, "c");

	REQUIRE(test.SearchName("name").empty());
};

TEST_CASE("SearchName for a 1 node tree", "[SearchName]") {
	GatorBST<string> test;

	test.Insert(7, "a");

	REQUIRE(test.SearchName("a") == vector<int>{7});
};

TEST_CASE("SearchName for names with multiple IDs.", "[SearchName]"){
	GatorBST<string> test;

	test.Insert(12, "a");
	test.Insert(7, "b");
	test.Insert(15, "c");
	test.Insert(3, "a");
	test.Insert(9, "b");
	test.Insert(20, "c");
	test.Insert(1, "a");

	REQUIRE(test.SearchName("a") == vector<int>{1, 3, 12});
	REQUIRE(test.SearchName("b") == vector<int>{7, 9});
	REQUIRE(test.SearchName("c") == vector<int>{15, 20});
};

TEST_CASE("SearchName for every node in a tree.", "[SearchName]") {
	GatorBST<string> test;

	test.Insert(10, "a");
	test.Insert(7, "b");
	test.Insert(15, "c");
	test.Insert(3, "d");
	test.Insert(9, "e");
	test.Insert(20, "f");
	test.Insert(1, "g");
	test.Insert(12, "g");

	REQUIRE(test.SearchName("a") == vector<int>{10});
	REQUIRE(test.SearchName("b") == vector<int>{7});
	REQUIRE(test.SearchName("c") == vector<int>{15});
	REQUIRE(test.SearchName("d") == vector<int>{3});
	REQUIRE(test.SearchName("e") == vector<int>{9});
	REQUIRE(test.SearchName("f") == vector<int>{20});
	REQUIRE(test.SearchName("g") == vector<int>{1, 12});
};

// ------------------REMOVE--CASES--------------------------------------------------------------------------------------

TEST_CASE("Remove in 1 node tree.", "[Remove]"){
	GatorBST<string> test;

    test.Insert(1, "a");

    REQUIRE(test.Remove(1) == true);
};

TEST_CASE("Remove in empty tree.", "[Remove]"){
	GatorBST<string> test;

    REQUIRE(test.Remove(1) == false);
};

TEST_CASE("Remove nonexistent node.", "[Remove]"){
	GatorBST<string> test;

	test.Insert(1, "a");
	test.Insert(3, "b");
	test.Insert(5, "c");
	test.Insert(7, "c");

	REQUIRE(test.Remove(12) == false);
};

TEST_CASE("Remove in right skewed tree.", "[Remove]"){
	GatorBST<string> test;

	test.Insert(1, "a");
	test.Insert(2, "b");
	test.Insert(3, "c");

	REQUIRE(test.Remove(1) == true);
	REQUIRE(test.Remove(2) == true);
	REQUIRE(test.Remove(3) == true);
};

TEST_CASE("Remove in left skewed tree.", "[Remove]"){
	GatorBST<string> test;

	test.Insert(3, "a");
	test.Insert(2, "b");
	test.Insert(1, "c");

	REQUIRE(test.Remove(3) == true);
	REQUIRE(test.Remove(2) == true);
	REQUIRE(test.Remove(1) == true);
};

TEST_CASE("Remove all nodes in a tree.", "[Remove]"){
	GatorBST<string> test;

	test.Insert(9, "a");
	test.Insert(7, "b");
	test.Insert(12, "c");
	test.Insert(8, "d");
	test.Insert(6, "e");
	test.Insert(10, "f");
	test.Insert(15, "g");

	REQUIRE(test.Remove(15) == true);
	REQUIRE(test.Remove(10) == true);
	REQUIRE(test.Remove(6) == true);
	REQUIRE(test.Remove(8) == true);
	REQUIRE(test.Remove(12) == true);
	REQUIRE(test.Remove(7) == true);
	REQUIRE(test.Remove(9) == true);
};

TEST_CASE("Remove node with a child.", "[Remove]"){
	GatorBST<string> test;

	test.Insert(5,"a");
	test.Insert(3,"b");
	test.Insert(12,"c");
	test.Insert(7,"d");

	REQUIRE(test.Remove(15) == true);
	REQUIRE(test.TraverseInorder() == vector<int>{3,5,7});
};

TEST_CASE("Remove nodes and check for inorder replacement", "[Remove]"){
	GatorBST<string> test;

	test.Insert(9, "a");
	test.Insert(7, "b");
	test.Insert(12, "c");
	test.Insert(8, "d");
	test.Insert(6, "e");
	test.Insert(10, "f");
	test.Insert(15, "g");

	// Inorder for original tree: 6, 7, 8, 9, 10, 12, 15

	SECTION("remove 9") {
          REQUIRE(test.Remove(9) == true);
          REQUIRE(test.TraverseInorder() == vector<int>{6, 7, 8, 10, 12, 15});
    };
	SECTION("remove 7") {
          REQUIRE(test.Remove(7) == true);
          REQUIRE(test.TraverseInorder() == vector<int>{6, 8, 9, 10, 12, 15});
    };
	SECTION("remove 12") {
          REQUIRE(test.Remove(12) == true);
          REQUIRE(test.TraverseInorder() == vector<int>{6, 7, 8, 9, 10, 15});
    };
	SECTION("remove 8") {
          REQUIRE(test.Remove(8) == true);
          REQUIRE(test.TraverseInorder() == vector<int>{6, 7, 9, 10, 12, 15});
    };
	SECTION("remove 6") {
          REQUIRE(test.Remove(6) == true);
          REQUIRE(test.TraverseInorder() == vector<int>{7, 8, 9, 10, 12, 15});
    };
	SECTION("remove 10") {
          REQUIRE(test.Remove(10) == true);
		  REQUIRE(test.TraverseInorder() == vector<int>{6, 7, 8, 9, 12, 15});
    };
	SECTION("remove 15") {
          REQUIRE(test.Remove(15) == true);
          REQUIRE(test.TraverseInorder() == vector<int>{6, 7, 8, 9, 10, 12});
    };
};

// ------------------TRAVERSAL--CASES-----------------------------------------------------------------------------------

TEST_CASE("Checking Traversal Methods with an empty tree.", "[Inorder][Preorder][Postorder]"){
	GatorBST<string> test;

	SECTION("Inorder Test") {
		REQUIRE(test.TraverseInorder().empty());
	};

	SECTION("Preorder Test") {
		REQUIRE(test.TraversePreorder().empty());
	};

	SECTION("Postorder Test") {
		REQUIRE(test.TraversePostorder().empty());
	};
};

TEST_CASE("Checking Traversal Methods in 1 node tree", "[Inorder][Preorder][Postorder]"){
	GatorBST<string> test;

	test.Insert(9, "a");

	SECTION("Inorder Test") {
		REQUIRE(test.TraverseInorder() == vector<int>{9});
	};

	SECTION("Preorder Test") {
		REQUIRE(test.TraversePreorder() == vector<int>{9});
	};

	SECTION("Postorder Test") {
		REQUIRE(test.TraversePostorder() == vector<int>{9});
	};
};

TEST_CASE("Checking Traversal Methods in right skewed tree", "[Inorder][Preorder][Postorder]"){
	GatorBST<string> test;

	test.Insert(1, "a");
	test.Insert(2, "b");
	test.Insert(3, "c");
	test.Insert(4, "d");
	test.Insert(5, "e");
	test.Insert(6, "f");
	test.Insert(7, "g");


	SECTION("Inorder Test") {
		REQUIRE(test.TraverseInorder() == vector<int>{1, 2, 3, 4, 5, 6, 7});
	};

	SECTION("Preorder Test") {
		REQUIRE(test.TraversePreorder() == vector<int>{1, 2, 3, 4, 5, 6, 7});
	};

	SECTION("Postorder Test") {
		REQUIRE(test.TraversePostorder() == vector<int>{7, 6, 5, 4, 3, 2, 1});
	};
};

TEST_CASE("Checking Traversal Methods in left skewed tree", "[Inorder][Preorder][Postorder]"){
	GatorBST<string> test;

	test.Insert(7, "a");
	test.Insert(6, "b");
	test.Insert(5, "c");
	test.Insert(4, "d");
	test.Insert(3, "e");
	test.Insert(2, "f");
	test.Insert(1, "g");


	SECTION("Inorder Test") {
		REQUIRE(test.TraverseInorder() == vector<int>{1, 2, 3, 4, 5, 6, 7});
	};

	SECTION("Preorder Test") {
		REQUIRE(test.TraversePreorder() == vector<int>{7, 6, 5, 4, 3, 2, 1});
	};

	SECTION("Postorder Test") {
		REQUIRE(test.TraversePostorder() == vector<int>{1, 2, 3, 4, 5, 6, 7});
	};
};

TEST_CASE("Checking Traversal Methods balanced tree.", "[Inorder][Preorder][Postorder]"){
	GatorBST<string> test;

	test.Insert(9, "a");
	test.Insert(7, "b");
	test.Insert(12, "c");
	test.Insert(8, "d");
	test.Insert(6, "e");
	test.Insert(10, "f");
	test.Insert(15, "g");


	SECTION("Inorder Test") {
		REQUIRE(test.TraverseInorder() == vector<int>{6, 7, 8, 9, 10, 12, 15});
	};

	SECTION("Preorder Test") {
		REQUIRE(test.TraversePreorder() == vector<int>{9, 7, 6, 8, 12, 10,15});
	};

	SECTION("Postorder Test") {
		REQUIRE(test.TraversePostorder() == vector<int>{6, 8, 7, 10, 15, 12, 9});
	};
};

TEST_CASE("Checking Traversal Methods in a unbalanced tree.", "[Inorder][Preorder][Postorder]"){
	GatorBST<string> test;

	test.Insert(8, "a");
	test.Insert(4, "b");
	test.Insert(12, "c");
	test.Insert(5, "d");
	test.Insert(3, "e");
	test.Insert(20, "f");
	test.Insert(7, "f");


	SECTION("Inorder Test") {
		REQUIRE(test.TraverseInorder() == vector<int>{3,4,5,7,8,12,20});
	};

	SECTION("Preorder Test") {
		REQUIRE(test.TraversePreorder() == vector<int>{8,4,3,5,7,12,20});
	};

	SECTION("Postorder Test") {
		REQUIRE(test.TraversePostorder() == vector<int>{3,7,5,4,20,12,8});
	};
};

// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...
