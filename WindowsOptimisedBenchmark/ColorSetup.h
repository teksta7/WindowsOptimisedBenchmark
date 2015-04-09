#pragma once

template < typename T>
class ColorSetup
{
public:
	typedef std::map<float, typename T> Map;
	typedef typename Map::iterator Iterate;
	typedef typename Map::const_iterator CONSTiterator;

};

