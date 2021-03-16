# -*- coding: utf-8 -*-

# @File    : main.py
# @Date    : 2020-10-27
# @Author  : 王超逸
# @Brief   : 


# 空转移
epsilon = "__epsilon__"


class Node:
    def __init__(self):
        self.fan_out = {}
        # 是否是一个终点
        self.is_end = False

    def link_to(self, char: str, node: 'Node'):
        """
        连接到另一个节点
        :param char:
        :param node:
        :return:
        """
        t = self.fan_out.get(char, [])
        t.append(node)
        self.fan_out[char] = t

    def get_transfer(self, char: str):
        """
        取得符合条件的转移
        :param char:
        :return:
        """
        return set(self.fan_out.get(char, [])) | set(self.fan_out.get('.', []))

    def get_epsilon(self):
        return set(self.fan_out.get(epsilon, []))


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        start = self.build_NFA(p)
        return self.search(s, start, 0)

    def search(self, s: str, it: Node, index: int):
        """
        递归搜索状态.
        我掐指一算，用递归写可以节约好几行代码，还能节约一个队列。
        因为长度小于30，所以我们不用考虑效率
        :param s: 要匹配的字符串
        :param it: 指向当前状态
        :param index: 指向当前字符
        :return:
        """
        if index == len(s) and it.is_end:
            return True
        # 即使到了字符串末尾，依然应该先做空转移
        for node in it.get_epsilon():
            if self.search(s, node, index):
                return True
        # 到了末尾，做了空转移，不是接受状态
        if index == len(s):
            return False
        # 对于正常转移和epsilon转移，唯一不同之处在于要不要消耗一个字符
        for node in it.get_transfer(s[index]):
            if self.search(s, node, index + 1):
                return True

        return False

    @staticmethod
    def build_NFA(p: str) -> Node:
        """
        根据模式创建一个自动机
        :param p: 模式
        :return: 自动机开始节点
        """
        start = Node()
        it = start
        i = 0
        while i < len(p):
            new_node = Node()
            if i < len(p) - 1 and p[i + 1] == "*":
                # 如果是克林闭包
                it.link_to(p[i], it)
                it.link_to(epsilon, new_node)
                # 额外+1，跳过后面的星号
                i += 1

            else:
                # 星号被跳过了，而且不可能有连续星号
                assert p[i] != "*"
                # 如果不是闭包
                it.link_to(p[i], new_node)
            it = new_node
            i += 1
        it.is_end = True
        return start

s = Solution()
print(s.isMatch("222272222722227", "2*7.*27"))