class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        populations = []
        tmps = []

        # Go one by one in nums
        # Create a list of permutations and populations
        # Each time take an item from populations, append your number to every position and save them in populations
        for i in nums:
            # When the list is empty
            if len(populations) == 0:
                populations.append([i])
                continue
            
            # Otherwise take the items in the populations
            for pop in populations:
                for index in range(0, len(pop)+1):
                    tmp = pop.copy()
                    tmp.insert(index, i)
                    tmps.append(tmp)
            
            # Replace populations
            populations = tmps
            tmps = []

        hashes = {}
        selected = []
        for i in populations:
            hashing = str(i)
            if hashing not in hashes:
                hashes[hashing] = True
                selected.append(i)

        return selected
