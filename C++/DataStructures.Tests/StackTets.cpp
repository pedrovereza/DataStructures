#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DataStructures\Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTests
{		
	TEST_CLASS(StackTests)
	{
	public:
		Stack<std::string> stack;

		TEST_METHOD_CLEANUP(TearDown)
		{
			stack.Clear();
		}

		TEST_METHOD(Clear_Should_Remove_All_Nodes)
		{
			stack.Push("data 1");
			stack.Push("data 2");
			stack.Push("data 3");
			stack.Push("data 4");

			stack.Clear();

			Assert::IsTrue(stack.IsEmpty());
		}

		TEST_METHOD(Pop_Should_Return_And_Remove_Element)
		{
			stack.Push("data 1");
			
			std::string* data = stack.Pop();

			Assert::AreEqual(std::string("data 1"), (*data));
			Assert::IsTrue(stack.IsEmpty());
		}

		TEST_METHOD(Peek_Should_Return_And_Keep_Element)
		{
			stack.Push("data 1");

			std::string* data = stack.Peek();

			Assert::AreEqual(std::string("data 1"), (*data));
			Assert::IsFalse(stack.IsEmpty());
		}

		TEST_METHOD(Empty_Returns_True_When_Stack_Contains_No_Elements)
		{
			Assert::IsTrue(stack.IsEmpty());
		}
	};
}