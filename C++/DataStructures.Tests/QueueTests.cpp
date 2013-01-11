#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DataStructures\Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTests
{		
	TEST_CLASS(QueueTests)
	{
	public:
		Queue<char> queue;

		TEST_METHOD_CLEANUP(TearDown)
		{
			queue.Clear();
		}

		TEST_METHOD(Enqueue_Should_Add_Element_At_The_End_Of_The_Queue)
		{
			queue.Enqueue('a');
			Assert::AreEqual('a', (*queue.Peek()));

			queue.Enqueue('b');
			Assert::AreEqual('a', (*queue.Peek()));
		
			queue.Enqueue('c');
			Assert::AreEqual('a', (*queue.Peek()));
		}

		TEST_METHOD(Dequeue_Should_Return_And_Remove_Element_At_Begin)
		{
			queue.Enqueue('a');
			queue.Enqueue('b');

			Assert::AreEqual('a', (*queue.Dequeue()));
			Assert::AreEqual('b', (*queue.Peek()));
		}

		TEST_METHOD(Elements_Are_Dequeued_In_The_Same_Order_They_Were_Enqueued)
		{
			queue.Enqueue('a');
			queue.Enqueue('b');
			queue.Enqueue('c');

			Assert::AreEqual('a', (*queue.Dequeue()));
			Assert::AreEqual('b', (*queue.Dequeue()));
			Assert::AreEqual('c', (*queue.Dequeue()));
		}
	};
}