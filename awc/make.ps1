param(
  [string]$name = "output"
)

robocopy "template" $name /E /NFL /NDL /NJH /NJS /NC /NS | Out-Null

Write-Output "Successfully Copied!"