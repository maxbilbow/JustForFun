package Interviews.acano;

import java.util.Collection;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

public class LinkedDict<K,V> implements Map<K,V> {

	public class KeyValuePair {
		K key; V value;
		KeyValuePair(K key,V value) {
			this.key = key;
			this.value = value;
		}
	}
	
	private LinkedList<K> keys = new LinkedList<>();
	private LinkedList<V> values = new LinkedList<>();
	
	@Override
	public int size() {
		// TODO Auto-generated method stub
		return keys.size();
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return keys.isEmpty();
	}

	@Override
	public boolean containsKey(Object key) {
		// TODO Auto-generated method stub
		return keys.contains(key);
	}

	@Override
	public boolean containsValue(Object value) {
		// TODO Auto-generated method stub
		return values.contains(value);
	}

	@Override
	public V get(Object key) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public V put(K key, V value) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public V remove(Object key) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void putAll(Map<? extends K, ? extends V> m) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void clear() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Set<K> keySet() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Collection<V> values() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Set<java.util.Map.Entry<K, V>> entrySet() {
		// TODO Auto-generated method stub
		return null;
	}

}
