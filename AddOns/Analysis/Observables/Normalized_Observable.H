#ifndef Analysis_Observables_Normalized_Observable_H
#define Analysis_Observables_Normalized_Observable_H

#include "AddOns/Analysis/Observables/Primitive_Observable_Base.H"

namespace ANALYSIS {

  class Normalized_Observable: public Primitive_Observable_Base {  
  protected:
    
    ATOOLS::Histogram *p_obs, *p_norm;

    int m_mode;

  public:

    // constructors
    Normalized_Observable();
    Normalized_Observable(int type,double xmin,double xmax,int nbins,
			  const std::string &name="",const int mode=0);
    Normalized_Observable(const Normalized_Observable & old);

    // destructor
    ~Normalized_Observable();

    // member functions
    Primitive_Observable_Base &
    operator+=(const Primitive_Observable_Base &obs);

    void Reset();
    void Restore(double scale=1.0);
    void EndEvaluation(double scale=1.0);

    void Fill(const double &x,const double &y,
	      const double &weight,const double &ntrial);
    void FillMCB(const double &x,const double &y,
		 const double &weight,const double &ntrial);
    void FinishMCB();

    Primitive_Observable_Base *Copy() const;

    inline const std::string &Name() const { return p_obs->Name(); }

  };// end of class Normalized_Observable

}// end of namespace ANALYSIS

#endif
