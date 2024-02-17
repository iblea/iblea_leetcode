class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        student_queue = students
        limit_count = 0

        while True:
            if len(student_queue) == 0:
                return 0

            if limit_count >= len(student_queue):
                break

            if student_queue[0] == sandwiches[0]:
                student_queue.pop(0)
                sandwiches.pop(0)
                limit_count = 0
                continue

            student_queue.append(student_queue.pop(0))
            limit_count += 1

        return len(student_queue)
