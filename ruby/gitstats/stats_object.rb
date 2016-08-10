class StatsObject
    @rebases = 0
    @commits = 0
    @merges = 0

    def rebases=(value)
        @rebases = value
    end
    
    def commits=(value)
        @commits = value
    end
    
    def merges=(value)
        @merges = value
    end    

    def calculate
        # points:
        # 1 - commit
        # 10 - rebase commits
        # 10 - merge commits
        # 5 - branchs merged into master (whatever br is in production)
        
        total = @rebases * 10
        total += @commits
        total += @merges * 10
    end
end