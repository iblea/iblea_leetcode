#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/video-stitching/

You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.
Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.
We can cut these clips into segments freely.
For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.

몇 초 동안 지속된 스포츠 이벤트의 일련의 비디오 클립이 주어집니다. 이 비디오 클립은 서로 겹칠 수 있으며 길이가 다양할 수 있습니다.
각 비디오 클립은 배열 클립으로 설명되며, 클립[i] = [starti, endi]는 i번째 클립이 시작점에서 시작하여 종료되었음을 나타냅니다.
이러한 클립을 자유롭게 세그먼트로 자를 수 있습니다.
예를 들어, 클립[0, 7]을 세그먼트[0, 1] + [1, 3] + [3, 7]로 자를 수 있습니다.
필요한 최소 클립 수를 반환하여 전체 스포츠 이벤트[0, 시간]를 포함하는 세그먼트로 클립을 자를 수 있도록 합니다. 작업이 불가능한 경우 -1을 반환합니다.

1 <= clips.length <= 100
0 <= starti <= endi <= 100
1 <= time <= 100
"""

# Leet Code Solution

class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:

        timedict = {}

        for clip in clips:
            start_time = clip[0]
            end_time = clip[1]
            if start_time >= end_time:
                continue

            if start_time in timedict:
                timedict[start_time] = max(timedict[start_time], end_time)
            else:
                timedict[start_time] = end_time


        max_clip_time = 0
        ago_count = -1
        count = 0
        idx = 0
        idx_remember = 0
        while idx < time:
            if ago_count == idx:
                if max_clip_time == 0:
                    return -1

                ago_count = idx_remember
                idx = max_clip_time
                idx_remember = idx
                max_clip_time = 0
                count += 1
                continue

            max_clip_time = max(max_clip_time, timedict.get(idx, 0))
            idx -= 1

        return count


















# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        pass

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        res = self.solution.videoStitching(clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10)
        self.assertEqual(res, 3)
        """
        Explanation: We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
        Then, we can reconstruct the sporting event as follows:
        We cut [1,9] into segments [1,2] + [2,8] + [8,9].
        Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
        """

    def test_case_2(self):
        res = self.solution.videoStitching(clips = [[0,1],[1,2]], time = 5)
        self.assertEqual(res, -1)
        """
        Explanation: We cannot cover [0,5] with only [0,1] and [1,2].
        """

    def test_case_3(self):
        res = self.solution.videoStitching(clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], time = 9)
        self.assertEqual(res, 3)
        """
        Explanation: We can take clips [0,4], [4,7], and [6,9].
        """

    def test_case_4(self):
        res = self.solution.videoStitching(clips = [[0,7],[6,8],[5,8],[5,7],[4,9]], time = 9)
        self.assertEqual(res, 2)
        """
        Explanation: We can take clips [0,4], [4,7], and [6,9].
        """

    def test_case_5(self):
        res = self.solution.videoStitching([[0,6],[7,7],[4,8],[0,5],[4,7],[0,7],[9,9],[3,3],[6,10],[2,9]], 15)
        self.assertEqual(res, -1)
        """
        Explanation: We can take clips [0,4], [4,7], and [6,9].
        """





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
