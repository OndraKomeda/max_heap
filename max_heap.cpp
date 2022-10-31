#include <vector>

class Max_Heap {
private:
	std::vector<int> m_arr;

	int parent_index(int index) { return (index-1) / 2; }
	int left_child_index(int index) { return (index * 2) + 1; }
	int right_child_index(int index) { return (index * 2) + 2; }
	/// <summary>
	/// Moves value down in binary heap until it's on the right place.
	/// </summary>
	/// <param name="index">- Index of the value.</param>
	void shift_down(int index);
	/// <summary>
	/// Moves value up in binary heap until it's on the right place.
	/// </summary>
	/// <param name="index">Index of the value.</param>
	void shift_up(int index);

public:
	int get_max() { return m_arr[0]; }
	int pop_max();
	void insert(int data);
};

void Max_Heap::insert(int data) {

	m_arr.push_back(data);
	shift_up(m_arr.size() - 1);
}

int Max_Heap::pop_max() {

	int temp = m_arr[0];
	std::swap(m_arr[0], m_arr[m_arr.size() - 1]);
	m_arr.pop_back();
	shift_down(0);
	return temp;
}

void Max_Heap::shift_down(int index) {

	if (m_arr.size() - 1 < left_child_index(index)) 
		return;

	if (m_arr[index] < m_arr[left_child_index(index)]) {
		if (m_arr.size() - 1 < right_child_index(index) || m_arr[left_child_index(index)] > m_arr[right_child_index(index)]) {
			std::swap(m_arr[index], m_arr[left_child_index(index)]);
			shift_down(left_child_index(index));
			return;
		}
	}

	if (!(m_arr.size() - 1 < right_child_index(index)) && m_arr[index] < m_arr[right_child_index(index)]) {
		std::swap(m_arr[index], m_arr[right_child_index(index)]);
		shift_down(right_child_index(index));
	}
}

void Max_Heap::shift_up(int index) {

	if (m_arr[index] <= m_arr[parent_index(index)]) {
		return;
	}

	std::swap(m_arr[index], m_arr[parent_index(index)]);
	shift_up(parent_index(index));
}
