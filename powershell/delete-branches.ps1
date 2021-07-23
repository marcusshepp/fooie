cd ~/projects/da/da_ui
$branches = (git branch) | Out-String
$branches = $branches.Split([Environment]::NewLine)

for ($num = 0; $num -lt $branches.Count; $num++) {
    $branch = $branches[$num] -replace '\s',''

    if (![string]::IsNullOrEmpty($branch) -and !($branch -match "Release_Candidate") -and !($branch -match "master")) {
        $answer = read-host "delete this branch? ${branch}
            ${[Environment]::NewLine} y == delete locally
            ${[Environment]::NewLine} 0 == delete local and remote
            ${[Environment]::NewLine} n == do not delete ${[Environment]::NewLine}"

        if ($answer -eq "y") {
            git branch -D $branch
        } elseif ($answer -eq "o") {
            git branch -D $branch
            git push origin --delete $branch
        } elseif ($answer -eq "n") {
            write-output "Not Deleting: ${branch}"
        }

    }

}