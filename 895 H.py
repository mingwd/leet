class FreqStack(object):

    def __init__(self):
        self.freq = {}  # Dictionary to store the frequency of each value
        self.group = {}  # Dictionary to store stacks of elements grouped by frequency
        self.maxFreq = 0  # Variable to keep track of the maximum frequency

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        # Update frequency of the value
        self.freq[val] = self.freq.get(val, 0) + 1
        freq = self.freq[val]
        
        # Update the max frequency
        self.maxFreq = max(self.maxFreq, freq)
        
        # Add the value to the group corresponding to its frequency
        if freq not in self.group:
            self.group[freq] = []
        self.group[freq].append(val)

    def pop(self):
        """
        :rtype: int
        """
        # Get the most frequent group's stack
        val = self.group[self.maxFreq].pop()
        
        # Decrease the frequency of the value
        self.freq[val] -= 1
        
        # If the current frequency stack is empty, reduce maxFreq
        if not self.group[self.maxFreq]:
            self.maxFreq -= 1
        
        return val
