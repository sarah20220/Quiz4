// Note - the autograder expects this exact include for your catch code! If you use the manual catch compilation method, be sure you put this include back before submitting.
#include <catch2/catch_test_macros.hpp>

#include "GatorBST.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Checking insert with only right child.", "[Insert]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	REQUIRE(test.insert(1, "a") == true);
	REQUIRE(test.insert(2, "b") == true);
	REQUIRE(test.insert(3, "c") == true);
}
TEST_CASE("Checking insert with only left child.", "[Insert]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	REQUIRE(test.insert(3, "a") == true);
	REQUIRE(test.insert(2, "b") == true);
	REQUIRE(test.insert(1, "c") == true);
}
TEST_CASE("Checking insert allows duplicate names.", "[Insert]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	REQUIRE(test.insert(1, "a") == true);
	REQUIRE(test.insert(2, "a") == false);
}
TEST_CASE("Checking insert doesn't allow duplicate UIDs.", "[Insert]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	REQUIRE(test.insert(1, "a") == true);
	REQUIRE(test.insert(1, "b") == false);
}
TEST_CASE("Checking insert.", "[Insert]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "node");
	test.insert(10, "node");
	test.insert(15, "node");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 1);
}


TEST_CASE("Checking height of a balanced tree.", "[Height]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "a");
	test.insert(7, "b");
	test.insert(12, "c");
	test.insert(8, "d");
	test.insert(6, "e");
	test.insert(10, "f");
	test.insert(15, "g");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 3);
}
TEST_CASE("Checking height of a asymmetric tree.", "[Height]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "a");
	test.insert(5, "b");
	test.insert(12, "c");
	test.insert(6, "d");
	test.insert(4, "e");
	test.insert(10, "f");
	test.insert(15, "g");
	test.insert(7, "h");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 4);
}
TEST_CASE("Checking height with only left child.", "[Height]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "root");
	test.insert(7, "one");
	test.insert(5, "two");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 3);
}
TEST_CASE("Checking height with only right child.", "[Height]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "root");
	test.insert(11, "one");
	test.insert(15, "two");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 3);
}
TEST_CASE("Checking height of empty tree.", "[Height]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 0);
}
TEST_CASE("Checking height only root.", "[Height]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(1, "root");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.height() == 1);
}


TEST_CASE("Check SearchID with empty tree.", "[SearchID]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	auto SearchResult = test.SearchID(1);
	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(SearchResult.has_value() == false);
}
TEST_CASE("Check SearchID with nonexistent ID.", "[SearchID]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(2, "a");
	test.insert(1, "b");
	test.insert(3, "c");

	auto SearchResult = test.SearchID(4);
	REQUIRE(SearchResult.has_value() == false);
}
TEST_CASE("Check SearchID with 1 node tree.", "[SearchID]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(1, "root");

   	REQUIRE(test.SearchID(1).value() == "root");

}
TEST_CASE("Check SearchID of every node in a 3 level tree.", "[SearchID]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "a");
	test.insert(5, "b");
	test.insert(12, "c");
	test.insert(6, "d");
	test.insert(4, "e");
	test.insert(10, "f");
	test.insert(15, "g");
	test.insert(7, "h");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	SECTION("a") { REQUIRE(test.SearchID(9).value() == "a"); }
	SECTION("b") { REQUIRE(test.SearchID(5).value() == "b"); }
	SECTION("c") { REQUIRE(test.SearchID(12).value() == "c"); }
	SECTION("d") { REQUIRE(test.SearchID(6).value() == "d"); }
	SECTION("e") { REQUIRE(test.SearchID(4).value() == "e"); }
	SECTION("f") { REQUIRE(test.SearchID(10).value() == "f"); }
	SECTION("g") { REQUIRE(test.SearchID(15).value() == "g"); }
	SECTION("h") { REQUIRE(test.SearchID(7).value() == "h"); }
};


TEST_CASE("SearchName in an empty tree.", "[SearchName]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

};
TEST_CASE("SearchName for nonexistent name.", "[SearchName]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

};
TEST_CASE("SearchName for a 1 node tree", "[SearchName]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

};
TEST_CASE("SearchName for multiple IDs.", "[SearchName]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

};
TEST_CASE("SearchName for every node in a 3 level tree.", "[SearchName]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

};

TEST_CASE("Remove in 1 node tree.", "[Remove]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
    test.insert(1, "a");
    REQUIRE(test.remove(1) == true);
};
TEST_CASE("Remove in empty tree.", "[Remove]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;
    REQUIRE(test.Remove(1) == false);
};
TEST_CASE("Remove in left skewed tree.", "[Remove]"){

	// instantiate any class members that you need to test here
	GatorBST<string> test;



};
TEST_CASE("Remove in right skewed tree.", "[Remove]"){
	// instantiate any class members that you need to test here
	GatorBST<string> test;

};
TEST_CASE("Remove all nodes in a tree.", "[Remove]"){
	// instantiate any class members that you need to test here
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "a");
	test.insert(7, "b");
	test.insert(12, "c");
	test.insert(8, "d");
	test.insert(6, "e");
	test.insert(10, "f");
	test.insert(15, "g");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(test.Remove(15) == true); }
	REQUIRE(test.Remove(10) == true); }
	REQUIRE(test.Remove(6) == true); }
	REQUIRE(test.Remove(8) == true); }
	REQUIRE(test.Remove(12) == true); }
	REQUIRE(test.Remove(7) == true); }
	REQUIRE(test.Remove(9) == true); }
};
TEST_CASE("Remove nodes and check for inorder replacement", "[Remove]"){
	// instantiate any class members that you need to test here
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "a");
	test.insert(7, "b");
	test.insert(12, "c");
	test.insert(8, "d");
	test.insert(6, "e");
	test.insert(10, "f");
	test.insert(15, "g");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	SECTION("a") {
          REQUIRE(test.Remove(9) == true);
          REQUIRE(test.TraverseInorder() == );
    }
	SECTION("b") {
          REQUIRE(test.Remove(7) == true);
          REQUIRE(test.TraverseInorder() == );
    }
	SECTION("c") {
          REQUIRE(test.Remove(12) == true);
          REQUIRE(test.TraverseInorder() == );
    }
	SECTION("d") {
          REQUIRE(test.Remove(8) == true);
          REQUIRE(test.TraverseInorder() == );
    }
	SECTION("e") {
          REQUIRE(test.Remove(6) == true);
          REQUIRE(test.TraverseInorder() == );
    }
	SECTION("f") {
          REQUIRE(test.Remove(10) == true);
		  REQUIRE(test.TraverseInorder() == );
    }
	SECTION("g") {
          REQUIRE(test.Remove(15) == true);
          REQUIRE(test.TraverseInorder() == );
    }
};


TEST_CASE("Checking Traversal Methods", "[Inorder][Preorder][Postorder]"){
	// you can also use "sections" to share setup code between tests, for example:
	// instantiate any class members that you need to test here
	GatorBST<string> test;
	test.insert(9, "a");
	test.insert(7, "b");
	test.insert(12, "c");
	test.insert(8, "d");
	test.insert(6, "e");
	test.insert(10, "f");
	test.insert(15, "g");

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	SECTION("Inorder Test") {
		REQUIRE(num == 2);
	};

	SECTION("Preorder Test") {
		REQUIRE(num == 3);
	};

	SECTION("Postorder Test") {
		REQUIRE(num == 3);
	};

	// each section runs the setup code independently to ensure that they don't affect each other
}

// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...
