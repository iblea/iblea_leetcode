class Solution:

    def function(self, l):

        # 변경할 인덱스
        i = 0
        changed_index = -1
        cnt = 0
        changed = False
        while i < len(l):
            stri = l[i]
            for cnt in range(i+1, len(l)):

                if l[cnt] <= stri:
                    continue

                changed = True
                if changed_index < 0 or l[changed_index] <= l[cnt]:
                    changed_index = cnt


            # 변경할 인덱스를 찾았을 경우 반복문을 탈출한다.
            if changed:
                break

            i += 1

        if changed_index >= 0:
            l[i], l[changed_index] = l[changed_index], l[i]

        return l


    def maximumSwap(self, num: int) -> int:
        s = list(str(num))

        # s = self.function(s)
        s = self.function(s)

        return int("".join(s))

