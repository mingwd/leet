from collections import Counter
from types import List
# 这种太慢了不行

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        offset = len(words[0])
        result = []
        len_to_check = offset * len(words)

        for i in range(len(s) - len_to_check + 1):
            temp = words[:]
            j = i
            while j < i + len_to_check:
                if s[j: j + offset] in temp:
                    temp.remove(s[j: j + offset])
                    j += offset
                else:
                    break
            
            if not temp:
                result.append(i)

        return result
    
# 用dict来查询 #可以过，但是很慢

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        offset = len(words[0])
        len_to_check = offset * len(words)
        word_map = {}
        result = []

        for word in words:
            word_map[word] = word_map.get(word, 0) + 1
        
        for i in range(len(s) - len_to_check + 1):
            visited = {} # 这里让速度变慢
            j = i
            while j < i + len_to_check:
                word_to_check = s[j: j+offset]
                if word_to_check in word_map:
                    visited[word_to_check] = visited.get(word_to_check, 0) + 1 
                    if visited[word_to_check] > word_map[word_to_check]:
                        break
                    j += offset
                else:
                    break

            if j == i + len_to_check:
                result.append(i)

        return result
    
# 可以用counter


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_counts = Counter(words)
        unit_len = len(words[0])
        result = []

        for i in range(unit_len):
            left = i
            curr_counts = Counter()
            count = 0

            for j in range(i, len(s) - unit_len + 1, unit_len):
                word = s[j : j + unit_len]

                if word in word_counts:
                    curr_counts[word] += 1
                    count += 1
                    while curr_counts[word] > word_counts[word]:
                        need_remove = s[left:left+unit_len]
                        curr_counts[need_remove] -= 1
                        left += unit_len
                        count -= 1
                    if count == len(words):
                        result.append(left)
                else:
                    curr_counts.clear()
                    left = j + unit_len
                    count = 0

        return result

        



