def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    n = int(data[idx]); idx += 1
    k = int(data[idx]); idx += 1
    q = int(data[idx]); idx += 1
    
    # Step 1: Precompute bi,j using bitwise OR cumulative values
    a = []
    for i in range(n):
        row = list(map(int, data[idx:idx + k]))
        idx += k
        a.append(row)
    
    b = [[0] * k for _ in range(n)]
    
    # Initialize the first country's regions in b
    for j in range(k):
        b[0][j] = a[0][j]
    
    # Compute bi,j cumulatively
    for i in range(1, n):
        for j in range(k):
            b[i][j] = b[i - 1][j] | a[i][j]
    
    results = []
    
    # Step 2: Process each query
    for _ in range(q):
        m = int(data[idx]); idx += 1
        requirements = []
        for __ in range(m):
            r = int(data[idx]) - 1
            o = data[idx + 1]
            c = int(data[idx + 2])
            requirements.append((r, o, c))
            idx += 3
        
        # Step 3: Check conditions from country 1 to n
        valid_countries = []
        for i in range(n):
            valid = True
            for (r, o, c) in requirements:
                if o == '<' and not (b[i][r] < c):
                    valid = False
                    break
                elif o == '>' and not (b[i][r] > c):
                    valid = False
                    break
            if valid:
                valid_countries.append(i + 1)  # Store country number (1-based)
        
        # Get the minimum country number, or -1 if no valid country
        if valid_countries:
            results.append(min(valid_countries))
        else:
            results.append(-1)
    
    # Output all results
    sys.stdout.write('\n'.join(map(str, results)) + '\n')

