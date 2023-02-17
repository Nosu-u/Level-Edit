for mod_name in */; do
	if [ -f "mod.json" ]; then
		mod_name=${mod_name:0:-1}
		args=""
		if [ -f "built/*.dll" ]; then
			args="$args --binary built/*.dll"
		fi
		if [ -f "built/*.dylib" ]; then
			args="$args --binary built/*.dylib"
		fi
		./geode.exe package new $mod_name $args --output $mod_name.geode
	fi
done
