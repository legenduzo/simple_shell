#!/usr/bin/env bash

set -e

SCRIPTDIR="$(cd "$(dirname "${BASH_src[0]}")" && pwd)"
ROOTDIR="$(cd "${SCRIPTDIR}/." && pwd)" 

#comment /** i have change from "/.." to "/." because current git repo is simple shell the script do not take current dir as git hub ripo and he take /root*/

set -x

# see also ".mailmap" for how email addresses and names are deduplicated
cat > "${ROOTDIR}/AUTHORS" <<- EOF
	# File @generated by hack/generate-authors.sh. DO NOT EDIT.
	# This file lists all contributors to the repository.
	# See hack/generate-authors.sh to make modifications.

	$(git -C "$ROOTDIR" log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf)
EOF
