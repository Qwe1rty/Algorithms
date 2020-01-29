cmake_minimum_required(VERSION 3.8)
project(CLion)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Strings/Strings.h
        Strings/Solutions/LongestSubstringWithoutRepeatingCharacters.cpp
        Strings/Solutions/LongestPalindromicSubstring.cpp
        Strings/Solutions/ValidAnagram.cpp
        TwoPointers/TwoPointers.h
        TwoPointers/Solutions/ContainerWithMostWater.cpp
        TwoPointers/Solutions/FourSum.cpp
        TwoPointers/Solutions/FourSum2.cpp
        TwoPointers/Solutions/TrappingRainWater.cpp
        TwoPointers/Solutions/LongestConsecutiveSequence.cpp
        TwoPointers/Solutions/RangeSumQueryImmutable.cpp
        DynamicProgramming/DynamicProgramming.h
        DynamicProgramming/Solutions/BestTimeToBuyAndSellStock.cpp
        DynamicProgramming/Solutions/LongestValidParentheses.cpp
        DynamicProgramming/Solutions/DungeonGame.cpp
        DynamicProgramming/Solutions/CherryPickup.cpp
        DynamicProgramming/Solutions/MaximalSquare.cpp
        DynamicProgramming/Solutions/MinimumPathSum.cpp
        DynamicProgramming/Solutions/LongestIncreasingSubsequence.cpp
        DynamicProgramming/Solutions/UniquePaths.cpp
        DynamicProgramming/Solutions/PartitionEqualSubsetSum2.cpp
        DynamicProgramming/Solutions/PartitionEqualSubsetSum.cpp
        "DynamicProgramming/Solutions/Pow(x,n).cpp"
        TreesAndGraphs/Trees.h
        TreesAndGraphs/TreeNode.h
        TreesAndGraphs/Solutions/BinaryTreeInorderTraversal.cpp
        TreesAndGraphs/Solutions/NumberOfIslands.cpp
        LinkedLists/LinkedLists.h
        LinkedLists/ListNode.h
        LinkedLists/Solutions/MergeTwoSortedLists.cpp
        LinkedLists/Solutions/RemoveNthNodeFromEndOfList.cpp
        LinkedLists/Solutions/TaskScheduler.cpp
        DivideAndConquer/DivideAndConquer.h
        DivideAndConquer/Solutions/MergeKSortedLists.cpp
        DivideAndConquer/Solutions/KthLargestElementInAnArray.cpp
        DivideAndConquer/Solutions/KthLargestElementInAnArray2.cpp
        DivideAndConquer/Solutions/TheSkylineProblem.cpp
        DivideAndConquer/Solutions/KClosestPointsToOrigin.cpp
        DivideAndConquer/Solutions/Search2DMatrix.cpp
        DivideAndConquer/Solutions/Search2DMatrixII.cpp
        DivideAndConquer/Solutions/Search2DMatrixII2.cpp
        DivideAndConquer/Solutions/MergeSortedArray.cpp
        Stack/Stack.h
        Stack/Solutions/123Pattern.cpp
        Stack/Solutions/DailyTemperatures.cpp
        SlidingWindow/SlidingWindow.h
        SlidingWindow/Solutions/SlidingWindowMaximum.cpp
        SlidingWindow/Solutions/MaximumSubarray.cpp
        )
add_executable(CLion ${SOURCE_FILES})