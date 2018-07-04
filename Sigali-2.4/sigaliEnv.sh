# -----------------------------------------------
# This file loads Sigali in the environment.
# -----------------------------------------------
 
export Sigali_root="/home/osboxes/tmc/Sigali-2.4"
export Sigali_VERSION="2.4"
if [[ -e "${Sigali_root}/_config_bash" ]]; then
    source ${Sigali_root}"/_config_bash"
fi
if [ $SIGALI_PATH ]; then
    export SIGALI_PATH=""
fi
export SIGALI_PATH=".:${Sigali_root}/lib:${SIGALI_PATH}"
alias sigali='${Sigali_bin}/sigali'
