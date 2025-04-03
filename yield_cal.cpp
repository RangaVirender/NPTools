class MyMainFrame : public TGMainFrame
{
    private:
    
    TGGroupFrame *global_frame;  
    TGGroupFrame *grid_frame_1;  
    TGGroupFrame *grid_frame_2;  
    TGGroupFrame *grid_frame_3;  
    TGGroupFrame *grid_frame_4;
    TGButtonGroup *yield_cal_mode_button_group;
    TGRadioButton *select_yield_cal_button;  
    TGRadioButton *select_crxn_cal_button;  
    TGTextButton *cal_yield_button; 
    TGTextButton *exit_button; 
    TGTextView   *text_output; 
    TGLabel      *proj_charge_state_label;
    TGLabel      *total_charge_incident_label;
    TGLabel      *total_no_of_proj_label;
    TGLabel      *proj_label;
    TGLabel      *target_massNo_label;
    TGLabel      *target_density_label;
    TGLabel      *total_no_of_target_nuclei_label;
    TGLabel      *target_nuclei_label;
    TGLabel      *det_radius_label;
    TGLabel      *det_dis_label;
    TGLabel      *det_eff_label;
    TGLabel      *det_solid_angle_label;
    TGLabel      *solid_angle_label;
    TGLabel      *det_label;
    TGLabel      *rxn_crxn_label;
    TGLabel      *yield_label;
    TGLabel      *yield_value_label;

    
    TGNumberEntry *proj_charge_state_entry;
    TGNumberEntry *total_charge_incident_entry;
    TGNumberEntry *target_massNo_entry;
    TGNumberEntry *target_density_entry;
    TGNumberEntry *det_radius_entry;
    TGNumberEntry *det_dis_entry;
    TGNumberEntry *det_eff_entry;
    TGNumberEntry *rxn_crxn_entry;
    TGNumberEntry *yield_entry;
    
    //TGString total_no_of_proj_string;

    int    total_charge_incident_int;
    double total_no_of_proj_double;
    int    proj_charge_state_int;
    int    target_massNo_int;
    double target_density_double;
    double total_no_of_target_nuclei_double;
    double det_radius_double;
    double det_dis_double;
    double det_solid_angle_double;
    double det_eff_double;
    double rxn_crxn_double;
    double yield_double;
    double yield_crxn_factor;
    int width_pixel, height_pixel;

    public:
    MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
    virtual ~MyMainFrame();
    void cal_yield_button_clicked();
    void update_text_output();  
    void exit_button_clicked();
    void OnValueSet();
    TGString to_TGString(double); 
    virtual void CloseWindow(); 
    
};


MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) : TGMainFrame(p, w, h) 
{
    Pixel_t lightgray_color;
    gClient->GetColorByName("lightgray",lightgray_color);
    
    global_frame = new TGGroupFrame(this, "-", kHorizontalFrame);
    
    grid_frame_1 = new TGGroupFrame(global_frame, "Projectile parameters", kVerticalFrame);
   
    proj_charge_state_label = new TGLabel(grid_frame_1, "Projectile charge state");
   // proj_charge_state_label->ChangeBackground(lightgray_color);
    grid_frame_1->AddFrame(proj_charge_state_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    proj_charge_state_entry = new TGNumberEntry(grid_frame_1, 1, 3, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    proj_charge_state_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 1, 20);
    grid_frame_1->AddFrame(proj_charge_state_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    total_charge_incident_label = new TGLabel(grid_frame_1, "Total charge incident (nano Coulomb)");
    grid_frame_1->AddFrame(total_charge_incident_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    total_charge_incident_entry = new TGNumberEntry(grid_frame_1, 10000, 8, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    total_charge_incident_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_1->AddFrame(total_charge_incident_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    proj_label = new TGLabel(grid_frame_1, "Total no of projectiles:");
    grid_frame_1->AddFrame(proj_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    total_no_of_proj_label = new TGLabel(grid_frame_1, "");
    total_no_of_proj_label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));
    grid_frame_1->AddFrame(total_no_of_proj_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    grid_frame_2 = new TGGroupFrame(global_frame, "Target parameters", kVerticalFrame);
    
    target_massNo_label = new TGLabel(grid_frame_2, "Target Mass no");
    grid_frame_2->AddFrame(target_massNo_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    target_massNo_entry = new TGNumberEntry(grid_frame_2, 16, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    target_massNo_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_2->AddFrame(target_massNo_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    target_density_label = new TGLabel(grid_frame_2, "Target density (ug/cm2)");
    grid_frame_2->AddFrame(target_density_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    target_density_entry = new TGNumberEntry(grid_frame_2, 2200, 2, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    target_density_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e7);
    grid_frame_2->AddFrame(target_density_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    target_nuclei_label = new TGLabel(grid_frame_2, "Total no of target nuclei:");
    grid_frame_2->AddFrame(target_nuclei_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    total_no_of_target_nuclei_label = new TGLabel(grid_frame_2, "");
    total_no_of_target_nuclei_label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));
    grid_frame_2->AddFrame(total_no_of_target_nuclei_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    grid_frame_3 = new TGGroupFrame(global_frame, "Detector geometry parameters", kVerticalFrame);
    
    det_radius_label = new TGLabel(grid_frame_3, "Detector Radius (cm)");
    grid_frame_3->AddFrame(det_radius_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_radius_entry = new TGNumberEntry(grid_frame_3, 4.44, 2, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_radius_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e3);
    grid_frame_3->AddFrame(det_radius_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_dis_label = new TGLabel(grid_frame_3, "Detector distance (cm)");
    grid_frame_3->AddFrame(det_dis_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_dis_entry = new TGNumberEntry(grid_frame_3, 20, 2, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_dis_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e4);
    grid_frame_3->AddFrame(det_dis_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_eff_label = new TGLabel(grid_frame_3, "Detector efficiency(%)");
    grid_frame_3->AddFrame(det_eff_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_eff_entry = new TGNumberEntry(grid_frame_3, 15, 3, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_eff_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 100.0);
    grid_frame_3->AddFrame(det_eff_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    solid_angle_label = new TGLabel(grid_frame_3, "Detector solid angle (Sr)");
    grid_frame_3->AddFrame(solid_angle_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));    

    det_solid_angle_label = new TGLabel(grid_frame_3, "");
    det_solid_angle_label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));
    grid_frame_3->AddFrame(det_solid_angle_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_label = new TGLabel(grid_frame_3, "");
    det_label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));
    grid_frame_3->AddFrame(det_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    grid_frame_4 = new TGGroupFrame(global_frame, "Calculate", kVerticalFrame);

    yield_cal_mode_button_group = new TGButtonGroup(grid_frame_4, "Calculator mode");
    
    select_yield_cal_button = new TGRadioButton(yield_cal_mode_button_group, "Yield calculator");
    select_crxn_cal_button  = new TGRadioButton(yield_cal_mode_button_group, "Cross-section calculator");
    grid_frame_4->AddFrame(yield_cal_mode_button_group, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    

    rxn_crxn_label = new TGLabel(grid_frame_4, "Reaction cross-section(milli barn)");
    grid_frame_4->AddFrame(rxn_crxn_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    rxn_crxn_entry = new TGNumberEntry(grid_frame_4, 100, 2, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    rxn_crxn_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e6);
    grid_frame_4->AddFrame(rxn_crxn_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    cal_yield_button = new TGTextButton(grid_frame_4, "Calculate");
    cal_yield_button->Connect("Clicked()", "MyMainFrame", this, "cal_yield_button_clicked()"); // Connect to click handler
    grid_frame_4->AddFrame(cal_yield_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));

    yield_label = new TGLabel(grid_frame_4, "Yield:");
    grid_frame_4->AddFrame(yield_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    //yield_value_label = new TGLabel(grid_frame_4, "");
   // yield_value_label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));
   // grid_frame_4->AddFrame(yield_value_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    

    yield_entry = new TGNumberEntry(grid_frame_4, 100, 6, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    yield_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e6);
    grid_frame_4->AddFrame(yield_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    

    exit_button = new TGTextButton(grid_frame_4, "Exit");
    exit_button->Connect("Clicked()", "MyMainFrame", this, "exit_button_clicked()"); // Connect to exit handler
    grid_frame_4->AddFrame(exit_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    

    global_frame->AddFrame(grid_frame_1, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY, 5, 5, 5, 5));
    global_frame->AddFrame(grid_frame_2, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY, 5, 5, 5, 5));
    global_frame->AddFrame(grid_frame_3, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY, 5, 5, 5, 5));
    global_frame->AddFrame(grid_frame_4, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY, 5, 5, 5, 5));
    
    AddFrame(global_frame, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY, 5, 5, 5, 5));
    
    //text_output = new TGTextView(this, 600, 300); // 200x100 pixels size
    //AddFrame(text_output, new TGLayoutHints(kLHintsExpandY, 10, 10, 0, 10));

    // Set up the main frame
    SetWindowName("CERN-ROOT based yield calculator by V. Ranga (2025)");
    MapSubwindows();
    Resize(GetDefaultSize());  // Automatically fit all widgets
    MapWindow();
}


MyMainFrame::~MyMainFrame() {
    // Cleanup dynamically allocated objects
    RemoveFrame(cal_yield_button);    delete cal_yield_button;
    Cleanup();
}

TGString MyMainFrame::to_TGString(double number_double)
{
    // Convert double to scientific notation string
    std::stringstream ss;
    ss << std::scientific << std::setprecision(2) << number_double;
    return TGString(ss.str().c_str());
    
}

void MyMainFrame::cal_yield_button_clicked()
{
    total_charge_incident_int = total_charge_incident_entry->GetNumber();
        proj_charge_state_int =     proj_charge_state_entry->GetNumber();
    
    total_no_of_proj_double = proj_charge_state_int * total_charge_incident_int * 1e-9/(1.6e-19);
    
        target_massNo_int =    target_massNo_entry->GetNumber();
    target_density_double = target_density_entry->GetNumber();

    total_no_of_target_nuclei_double = 6.022e23*1e-6*target_density_double/target_massNo_int;

    det_radius_double = det_radius_entry->GetNumber();
       det_dis_double =    det_dis_entry->GetNumber();
             
    det_solid_angle_double = 2.0*M_PI*(1.0 - det_dis_double/sqrt(pow(det_dis_double,2.0) + pow(det_radius_double, 2.0) ) );

    det_eff_double  = det_eff_entry->GetNumber()/100.0;

             total_no_of_proj_label->SetText(to_TGString(total_no_of_proj_double));
    total_no_of_target_nuclei_label->SetText(to_TGString(total_no_of_target_nuclei_double));
              det_solid_angle_label->SetText(to_TGString(det_solid_angle_double));
    
    yield_crxn_factor =   total_no_of_proj_double*
                          total_no_of_target_nuclei_double*
                          det_solid_angle_double*
                          det_eff_double/(4*M_PI);
           
    if(select_yield_cal_button->GetState() == kButtonDown) //kButtonDown means button is pressed
        {
          // std::cout << "select_yield_cal_button" << std::endl;
           rxn_crxn_double = rxn_crxn_entry->GetNumber()*1e-27;//per cm2 to mb
    
           yield_double = rxn_crxn_double*yield_crxn_factor;
           
           yield_entry->SetNumber(yield_double);
        }
    else if(select_crxn_cal_button->GetState() == kButtonDown)
            {
                //std::cout << "select_crxn_cal_button" << std::endl;
                yield_double = yield_entry->GetNumber();
               // cout << "yield_double: " << yield_double << endl; 
                rxn_crxn_double = yield_double/yield_crxn_factor;
               // cout << "yield_crxn_factor: " << yield_crxn_factor << endl;
                rxn_crxn_entry->SetNumber(rxn_crxn_double*1e27);;// per cm2 to mb
               
            }
    

    
    
             
    return;
}



// Function to update TGTextView in real time
void MyMainFrame::update_text_output()
{
    text_output->Update();  // Force immediate UI refresh
    gSystem->ProcessEvents(); // Process pending UI events
    return;
}



void MyMainFrame::exit_button_clicked()
{
   // text_output->AddLine("Exiting application..."); // Add exit message
    gApplication->Terminate(0); // Gracefully exit the application
}

// Properly handle window close
void MyMainFrame::CloseWindow() {
    std::cout << "Closing application...\n";
    gApplication->Terminate(0);  // Stops the ROOT event loop
}

int yield_cal() 
{
    TApplication app("ROOT Application", 0, nullptr);
    MyMainFrame *mainFrame = new MyMainFrame(gClient->GetRoot(), 700, 700);
    app.Run();

    delete mainFrame;
    return 0;
}
