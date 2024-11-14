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

