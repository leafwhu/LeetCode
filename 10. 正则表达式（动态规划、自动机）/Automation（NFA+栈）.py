class Node:
    def __init__(self, number):
        self.number = number
        self.next = dict()

    def get_outgoing_edges(self):
        outgoing_edges = list(self.next.keys())
        if 'epsilon' in outgoing_edges:
            outgoing_edges.remove('epsilon')
            outgoing_edges.append('epsilon')
        return outgoing_edges

    def get_next(self, char):
        if char != 'epsilon':
            return list(set(self.next.get(char, [])) | set(self.next.get('.', [])))
        elif char == 'epsilon':
            return list(set(self.next.get(char, [])))

    def linkToNode(self, char, node):
        t = self.next.get(char, [])
        t.append(node)
        self.next[char] = t

    def is_end(self):
        if len(self.next) == 0:
            return True
        else:
            return False


class Automation:
    def __init__(self):
        self.start = Node(0)

    def build_NFA(self, p: str):
        t = self.start
        index = 0
        number = 1
        while index < len(p):
            newNode = Node(number)
            number += 1
            if index + 1 < len(p) and p[index + 1] == '*':
                t.linkToNode(p[index], t)
                t.linkToNode("epsilon", newNode)
                index += 1
            else:
                t.linkToNode(p[index], newNode)
            index += 1
            t = newNode
        return self.start
    
    @staticmethod
    def char_match(si, pi):
        if si == pi:
            return True
        elif pi == '.' and si != '':
            return True
        return False

    def isMatch(self, s: str, p: str):
        index = 0
        t = self.start
        stack = [[index, t, t.get_outgoing_edges()]]
        loop = 0
        while len(stack) > 0:
            loop += 1
            index, t, t_outgoing_edges = stack.pop()
            if t.is_end() and index == len(s):
                return True
            elif t.is_end():
                # p走完了，s还没走完，回溯
                continue
            elif index == len(s) and ('epsilon' not in t_outgoing_edges):
                # s走完了，p还没走完，且无法通过epsilon到达后继节点，回溯
                continue

            # 永远先走epsilon（非贪婪）
            t_outgoing_edge = t_outgoing_edges.pop()
            if len(t_outgoing_edges) > 0:
                stack.append([index, t, t_outgoing_edges])

            # 如果匹配，向前走一步，并将当前状态入栈
            if t_outgoing_edge == 'epsilon' or self.char_match(s[index], t_outgoing_edge):
                # 对于用epsilon规范化后的NFA，每个字符的后继节点只有一个
                t = t.get_next(t_outgoing_edge)[0]
                if t_outgoing_edge != 'epsilon':
                    index += 1
                # elif t.is_end() and index == len(s) - 1:
                #     return True
                stack.append([index, t, t.get_outgoing_edges()])
        return False


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        a = Automation()
        a.build_NFA(p)
        return a.isMatch(s, p)


s = Solution()
print(s.isMatch("222272222722227","2*7.*27"))
# print(s.isMatch("aa","a*"))
# print(s.isMatch("a","ab*"))
# print(s.isMatch("ab",".*c"))
# print(s.isMatch("bab","b*a*"))
