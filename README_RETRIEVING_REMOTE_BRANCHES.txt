//To create a local branch from the remote GitHub repo
//
//first: check for new branches and link to them

$ git fetch Tell40

//if nothing shows, all branches are avaible already

//second: create 'HEAD' in remote branch

$ git checkout Tell40/branch_you_are_pulling

//this can be made easier with TABing after Tell40/ to list remote branches
//remote branches that have been 'feched' before wont show in the first step

//third: create local version of branch from the 'HEAD' for editing/updating

$ git checkout -b branch_you_are_pulling

//forth: continue as normal
