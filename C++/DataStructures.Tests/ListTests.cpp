#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DataStructures\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTests
{		
	TEST_CLASS(ListTests)
	{
	public:
		List<int> list;

		TEST_METHOD_CLEANUP(TearDown)
		{
			list.Clear();
		}
		
		TEST_METHOD(Should_Count_Elements_On_List)
		{
			list.Add(1);
			Assert::AreEqual(1, list.Count());

			list.Add(2);
			list.Add(3);
			Assert::AreEqual(3, list.Count());
		}

		TEST_METHOD(Clear_Should_Delete_All_Nodes_And_Reset_Count)
		{
			for (int i = 0; i < 5; i++)
				list.Add(i);

			list.Clear();

			Assert::AreEqual(0, list.Count());
			Assert::AreEqual(0, (*list.FirstOrDefault()));
		}

		TEST_METHOD(Contains_Should_Return_True_When_List_Contains_Given_Element)
		{
			for (int i = 0; i < 10; i++)
				list.Add(i);

			Assert::IsTrue(list.Contains(0));
			Assert::IsTrue(list.Contains(5));
			Assert::IsTrue(list.Contains(9));
		}

		TEST_METHOD(Contains_Should_Return_False_When_List_Does_Not_Contain_Given_Element)
		{
			for (int i = 0; i < 10; i++)
				list.Add(i);

			Assert::IsFalse(list.Contains(-1));
			Assert::IsFalse(list.Contains(10));
			Assert::IsFalse(list.Contains(999));
		}

		TEST_METHOD(GetAt_Should_Return_Correct_Element_If_Exists_On_List)
		{
			for (int i = 10; i > 0; i--)
				list.Add(i);

			Assert::AreEqual(10, (*list.GetAt(0)));
			Assert::AreEqual(1, (*list.GetAt(9)));
			Assert::IsNull(list.GetAt(25));
		}

		TEST_METHOD(FirstOrDefault_Should_Return_Default_Value_When_List_Is_Empty)
		{
			Assert::AreEqual(0, (*list.FirstOrDefault()));
		}

		TEST_METHOD(FirstOrDefault_Should_Return_First_Element_When_List_Is_Not_Empty)
		{
			list.Add(999);
			Assert::AreEqual(999, (*list.FirstOrDefault()));

			list.Add(10);
			Assert::AreEqual(999, (*list.FirstOrDefault()));
		}

		TEST_METHOD(RemoveAt_Should_Remove_Element_At_Given_Index)
		{
			list.Add(1);
			list.Add(2);
			list.Add(3);

			list.RemoveAt(1);

			Assert::AreEqual(2, list.Count());

			Assert::IsFalse(list.Contains(2));

			Assert::IsTrue(list.Contains(1));
			Assert::IsTrue(list.Contains(3));
		}

		TEST_METHOD(Last_Should_Return_Last_Element_On_List)
		{
			list.Add(1);
			list.Add(2);
			list.Add(3);

			Assert::AreEqual(3, (*list.Last()));
		}

		TEST_METHOD(Last_Should_Return_Null_When_List_Is_Empty)
		{
			Assert::IsNull(list.Last());
		}
	};
}