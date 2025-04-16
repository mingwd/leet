class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:


        result = []
        i = 0
        size = len(words)

        while i < size:
            line_len = len(words[i])
            j = i + 1
            while j < size and line_len + 1 + len(words[j]) <= maxWidth:
                line_len += 1 + len(words[j])
                j += 1
            
            line_words = words[i:j]
            space = maxWidth - sum(len(word) for word in line_words)

            num_words = j - i

            if j == size or num_words == 1:
                line = " ".join(line_words)
                line += " " * (maxWidth - len(line))
            else:
                slots = num_words - 1
                space_per_slot = space // slots
                space_extra = space % slots

                line = ''
                for k in range(slots):
                    line += line_words[k] + " " * (space_per_slot + (1 if k < space_extra else 0))
                line += line_words[-1]

            result.append(line)
            i = j

        return result


