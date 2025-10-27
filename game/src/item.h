//after: bool AddToGround (long lMapIndex, const PIXEL_POSITION& pos
//add:
		#ifdef ENABLE_RENEWAL_DROP
	private:
		DWORD m_dwDropOwnerPID = 0;
		bool  m_bOwnerOnlyVisible = false;
	public:
		void SetOwnerOnlyVisible (DWORD pid)
		{
			m_dwDropOwnerPID = pid;
			m_bOwnerOnlyVisible = (pid != 0);
		}
		void ClearOwnerOnlyVisible()
		{
			m_dwDropOwnerPID = 0;
			m_bOwnerOnlyVisible = false;
		}
		bool IsOwnerOnlyVisible() const
		{
			return m_bOwnerOnlyVisible;
		}
		DWORD GetDropOwnerPID() const
		{
			return m_dwDropOwnerPID;
		}
		bool IsVisibleTo (LPCHARACTER ch) const;
		#endif