import re

s = "abc123"
match = re.match(r'([a-zA-Z]*)(\d*)', s)
if match:
    letters = match.groups()
    if letters[0]:
        isdigit = False
else:
    print("No match found.")
    print(match)


def parse(s: str):
    print(tuple(x for x in re.split('\[|(\])', s) if x))


# s = []
# s.append("3[a]2[bc]")
# s.append("3[a2[c]]")
# s.append("2[abc]3[cd]ef")
# s.append("aaa2[afd]")
# for i in s:
#     parse(i)


class Solution1:


    def decodeString(self, s: str) -> str:
        items = list(x for x in re.split("(\])|\[", s) if x)
        pattern = r"([a-zA-Z]*)(\d*)"

        stk = []
        def concat():

            s1 = stk.pop()
            s2 = stk.pop()
            if s2.isdigit():
                s2 = int(s2) * s1
            else:
                s2 += s1
            stk.append(s2)


        for x in items:
            if x == r"]":
                s1 = stk.pop()
                s2 = stk.pop()
                if s2.isdigit():
                    s2 = int(s2) * s1
                else:
                    s2 += s1
                stk.append(s2)
            else:
                stk.extend([x for x in re.match(pattern, x).groups() if x])
        print(stk)
        print("".join(stk))
        while len(stk) > 1:
            concat()
        return "".join(stk)


# Solution().decodeString("3[a]2[bc]")
# Solution().decodeString("2[abc]3[cd]ef")
cases = {}

class Solution222:


    def decodeString(self, s: str) -> str:
        items = list(x for x in re.split("(\])|\[", s) if x)
        pattern = r"([a-zA-Z]*)(\d*)"

        stk = [""]

        for x in items:
            if x == r"]":
                s1 = stk.pop()
                s2 = stk.pop()
                if s2.isdigit():
                    s2 = int(s2) * s1
                else:
                    s2 += s1
                stk.append(s2)


            else:
                stk.extend([x for x in re.match(pattern, x).groups() if x])
            if len(stk) > 1 and not stk[-2].isdigit():
                t = stk.pop()
                stk[-1] += t

            print(stk)
        return "".join(stk)


class Solution:


    def decodeString(self, s: str) -> str:
        items = list(x for x in re.split("(\])|\[", s) if x)
        pattern = r"([a-zA-Z]*)(\d*)"

        stk = [""]
        items2 = []
        for x in items:
            if x != r"]":
                items2.extend([x for x in re.match(pattern, x).groups() if x])
            else:
                items2.append(x)

        for x in items2:
            if x == r"]":
                s1 = stk.pop()
                s2 = stk.pop()

                s2 = int(s2) * s1

                if stk[-1].isdigit():
                    stk.append(s2)
                else:
                    stk[-1] += s2

            elif x.isdigit():
                stk.append(x)
            else:
                if stk[-1].isdigit():
                    stk.append(x)
                else:
                    stk[-1] += x
        return "".join(stk)

cases["3[z]2[2[y]pq4[2[jk]e1[f]]]ef"] = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"
cases["3[a]2[bc]"] = "aaabcbc"
cases["3[a2[c]]"] = "accaccacc"
cases["sd2[f2[e]g]i"] = "sdfeegfeegi"
for k, v in cases.items():
    r = Solution().decodeString(k)
    if r != v:
        print("NOK")
        print(f"{r}")
        print(f"{v}")
    else:
        print("OK")