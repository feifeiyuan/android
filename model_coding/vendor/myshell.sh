#!/system/bin/sh
TAG="feifeiyuan"
function exe_log()
{
	local cmd="$@"
	local emsg="$(eval $cmd)"
	log -p d -t $TAG "$cmd $emsg"
}
exe_log "hello world"
exe_log "mkdir /data/result/"

